/*
 * title : place-bitmap.c  -  place bitmap on screen
 * begin : 2017-03-20 16:28:19 
 * note  : with Xlib API
 * make  : gcc -o place-bitmap place-bitmap.c -lXt -lX11
 * usage : type "./place-bitmap" in terminal.
 *         after drawing, click mouse button #1 for exit
 * depnd : libxt-dev for Ubuntu.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>

/* バナー指定 */
#include  "kinkyuu.xbm"
#define  PIX_bits    kinkyuu_bits
#define  PIX_width   kinkyuu_width
#define  PIX_height  kinkyuu_height


#define  FOREGROUND  "White"
#define  BACKGROUND  "Red"

//  grobal var.

XtAppContext app_con;
Widget   toplevel;

Display  *disp;
Window   win;
XSetWindowAttributes  attr;
Pixmap   kinkyuuPix;
GC       gc;

//  drawing area
int      width, height;

/*  functions  */

//  「緊急地震速報」バナー pixmap 作成
void 
drawKinkyuu(void )
{

  XColor  col_fg, col_bg, col_ex;

  /*  色を用意する  */
  XAllocNamedColor(XtDisplay(toplevel), DefaultColormap(XtDisplay(toplevel), 0), FOREGROUND, &col_fg, &col_ex);
  XAllocNamedColor(XtDisplay(toplevel), DefaultColormap(XtDisplay(toplevel), 0), BACKGROUND, &col_bg, &col_ex);

  /*  バナーをpixmapとして用意する  */
  kinkyuuPix = XCreatePixmapFromBitmapData(
                   XtDisplay(toplevel), XtWindow(toplevel), 
                   PIX_bits, PIX_width, PIX_height, 
                   col_fg.pixel,
                   col_bg.pixel,
                   DefaultDepth(XtDisplay(toplevel), 0));

  XCopyArea(XtDisplay(toplevel), kinkyuuPix, XtWindow(toplevel), gc,
      0, 0, PIX_width, PIX_height, 
      0, 0);

}



void
quit_proc()
{
    printf("this client exits normaly.\n");
    printf("thank you !\n");
    exit(0);
}

//  Resources ; Push Mouse button #1 for exit
String fallback_resources[] = {
    ".place-bitmap.translations: #override\\n\
     <Btn1Up>: Quit()",
    ".place-bitmap.geometry: 100x100",
    NULL,
};

XtActionsRec actions[] = {
    {"Quit", (XtActionProc)quit_proc},
};


int main(int argc, char *argv[])
{
    toplevel = XtVaAppInitialize(&app_con, "place-bitmap", NULL, 0,
				 &argc, argv, fallback_resources, NULL);

    XtAppAddActions(app_con, actions, XtNumber(actions));

    XtRealizeWidget(toplevel);

    //  allocate disp, win and gc here for evasive Bad drawable.
    //  because, drawables are need for aftre realise.
    disp = XtDisplay(toplevel);
    win  = XtWindow(toplevel);
    gc   = XCreateGC(disp, win, 0, 0);

    /* stop interposition of Window Manager */
    /* to place window from prog, delete window title bar */
    attr.override_redirect = True;
    XChangeWindowAttributes(disp, win, CWOverrideRedirect, &attr);
    XMapWindow(disp, win);

    //  get display sizes
    width  = DisplayWidth(disp, 0);
    height = DisplayHeight(disp, 0);
    printf("Display size : (%d, %d)\n", width, height);

    //  Move and Resize window 
    XMoveWindow(disp, win, (width-PIX_width)/2, height/4);
    XResizeWindow(disp, win, PIX_width, PIX_height);

    //  draw graphics
    drawKinkyuu();

    //  wait mouse button #1 clicking
    XtAppMainLoop(app_con);
}

