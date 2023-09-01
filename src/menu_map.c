/**
 * @brief   Adam's Disk Sonic Screwdriver - a File and Disk Manager
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose Drive menu
 */

#include <eos.h>
#include <smartkeys.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "state.h"
#include "globals.h"

void menu_map(void)
{
  char tmp[48];

  /* snprintf(tmp,sizeof(tmp),"   DEVICE %02u\n   %4uK SIZE\n   %4luK FREE",current_device,current_size,current_free); */
  /* smartkeys_display(NULL,NULL,NULL,"  FILE\n FUNCS"," DRIVE\n FUNCS","  CHANGE\n  DRIVE"); */
  /* smartkeys_status(tmp); */

  smartkeys_display(NULL,NULL," SELECT\n DRIVE","  PREV\n  PAGE","   NEXT\n   PAGE",NULL);
  snprintf(tmp,sizeof(tmp),"   VOLUME MAP\n   FOR DEVICE %02x",current_device);
  smartkeys_status(tmp);
  
  eos_start_read_keyboard();
  
  while (state==MENU_MAP)
    {
      switch(input())
	{
	case 0x1B:
	  state=DIRECTORY;
	  break;
	case 0x83:
	  break;
	case 0x84:
	  state=SELECT_DRIVE;
	  break;
	case 0x85:
	  break;
	case 0x86:
	  break;
	case 0x90:
	  wildcard_mode=!wildcard_mode;
	  break;
	default:
	  // handle_navigation_keys();
	  break;
	}
    }

  eos_end_read_keyboard();
}
