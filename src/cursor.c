/**
 * Cursor routines
 */

#include <video/tms99x8.h>
#include "cursor.h"

static const unsigned char selector_pattern_right[8] =
  {0x00,0x60,0x78,0x7E,0x7E,0x78,0x60,0x00};

static const unsigned char selector_pattern_left[8] =
  {0x00,0x06,0x1E,0x7E,0x7E,0x1E,0x06,0x00};

void cursor(bool t)
{
  vdp_vfill(0x3806,t == true ? 0xFF : 0x00, 2);
  vdp_vfill(0x1b00,0x00,4);
  vdp_vpoke(0x1b03,4);
}

void cursor_pos(unsigned char x, unsigned char y)
{
  vdp_vpoke(0x1b00,(y<<3));
  vdp_vpoke(0x1b01,(x<<3));
}

void selector(unsigned char t)
{
  switch(t)
    {
    case 0:
      vdp_vfill(0x3800,0x00,8);
      break;
    case 1:
      vdp_vwrite(selector_pattern_right,0x3800,sizeof(selector_pattern_right));
      break;
    case 2:
      vdp_vwrite(selector_pattern_left,0x3800,sizeof(selector_pattern_left));
      break;
    }

  // Set color, clear position
  
  vdp_vfill(0x1b00,0x00,4);
  vdp_vpoke(0x1b03,8);
}

void selector_pos(unsigned char x, unsigned char y)
{
  vdp_vpoke(0x1b00,(y<<3)-1);
  vdp_vpoke(0x1b01,(x<<3));
}
