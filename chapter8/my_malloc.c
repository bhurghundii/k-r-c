#include <stdlib.h>
#include <string.h>
typedef long Align;                // for alignment to long boundary

union header                       // block header:
{
  struct
  {
    union header *ptr;             // size of this block
    unsigned size;                 // size of this block
  } s;
  Align x;                         // force alignment
};
typedef union header Header;

static Header base;               // empty list to get started with
static Header *freep = NULL;       // start of free list
void *my_malloc(unsigned nbytes);
#define NALLOC 1024    // minimum #units to request

/* malloc: general-purpose storage allocator */
// say how much you want, it gives you a pointer to the memory block
void *my_malloc(unsigned nbytes)
{
  Header *p, *prevp;
  Header *morecore(unsigned);
  unsigned nunits;

  // check for valid input by seeing if its 0 or if its too big 
  // for its data type + the reserved space for the header object
  if (nbytes == 0) || (nbytes >= (UINT_MAX - sizeof(Header) ){
     printf("Error with memory request");
     return NULL;
  }

  nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;

  if ((prevp = freep) == NULL)  // no free list yet
    {
      base.s.ptr = freep = prevp = &base;
      base.s.size = 0;
    }
  for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
    {
      if (p->s.size >= nunits)               // big enough
	{
	  if (p->s.size == nunits)           // exactly
	    prevp->s.ptr = p->s.ptr;
	  else                               // allocate tail end
	    {
	      p->s.size -= nunits;
	      p += p->s.size;
	      p->s.size = nunits;
	    }
	  freep = prevp;
	  return (void *)(p+1);
	}
      if (p == freep)                       // wrapped around free list
	if ((p = morecore(nunits)) == NULL)
	  return NULL;                      // none left
    }
}

/* morecore: ask system for more memory */
Header *_morecore(unsigned nu)
{
  char *cp, *sbrk(int);
  Header *up;

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *) -1)          // no space at all
    return NULL;
  up = (Header *) cp;
  up->s.size = nu;
  _free((void *)(up + 1));
  return freep;
}

/* _free: put block ap in free list */
void _free(void *ap)
{
  if (ap == NULL) {
    printf("")
    return;
  }

  Header *bp, *p;

  if (bp->s.size == 0){
    printf("there is nothing to free since its 0");
    return;
  }

  bp = (Header *)ap - 1;    // point to block header
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;               // freed block at start of end of arena

  if (bp + bp->s.size == p->s.ptr)      // join to upper
    {
      bp->s.size += p->s.ptr->s.size;
      bp->s.ptr = p->s.ptr->s.ptr;
    }
  else
    bp->s.ptr = p->s.ptr;
  if (p + p->s.size == bp)
    {
      p->s.size += bp->s.size;
      p->s.ptr = bp->s.ptr;
    }
  else
    p->s.ptr = bp;
  freep = p;
}


// p is an pointer to a block of n characters we free 
void bfree(void * p, size_t n){
  if (p < NALLOC){
    printf("The block is smaller than the minimum size, so blocked");
    return;
  } 

  Header *bp = NULL;
  bp = (Header * ) p; // cast as a header pointer
  bp->s.size = (n / sizeof(Header));
  _free(bp + 1); // add one cause we -1 in free
}