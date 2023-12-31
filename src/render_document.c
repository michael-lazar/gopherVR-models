/********************************************************************
 * $Id: render_document.c,v 1.1.1.1 2002/01/18 16:34:30 lindner Exp $
 *
 * Copyright 1995 by the Regents of the University of Minnesota
 *
 * see the file "COPYRIGHT" in the distribution for conditions of use.
 *
 *********************************************************************/

#include <stdio.h>
#include "hungarian.h"
#include "vogl.h"
#include "lines.h"
#ifdef MACINTOSH
#include <fp.h>
#else
#include <math.h>
#endif

#include "render_document.h"


static void buildDocument( STRING Sz_title );


static void buildDocument( STRING Sz_title )
{
    L_NUMBER    rlN_i0 [3] = {  264, -408, -56 };
    L_NUMBER    rlN_i1 [3] = {  264, -408, -24 };
    L_NUMBER    rlN_i2 [3] = { -264, -408, -24 };
    L_NUMBER    rlN_i3 [3] = { -264, -408, -56 };
    L_NUMBER    rlN_i4 [3] = { -264,    0, -56 };
    L_NUMBER    rlN_i5 [3] = {  264,    0, -56 };
    L_NUMBER    rlN_i6 [3] = { -264,    0, -24 };
    L_NUMBER    rlN_i7 [3] = {  264,    0, -24 };


    /*
     * Box1
     */
    bgnpolygon();
        if ( NULL != Sz_title )
        {
            charstr( rlN_i1, 180.0, TEXT_DOCUMENT_COLOR, 200.0, 500.0, Sz_title );
        }
        v3i( rlN_i6 );
        v3i( rlN_i2 );
        v3i( rlN_i1 );
        v3i( rlN_i7 );
    endpolygon();
    bgnpolygon();
        v3i( rlN_i7 );
        v3i( rlN_i1 );
        v3i( rlN_i0 );
        v3i( rlN_i5 );
    endpolygon();
    bgnpolygon();
        if ( NULL != Sz_title )
        {
           charstr( rlN_i3, 0.0, TEXT_DOCUMENT_COLOR, 200.0, 500.0, Sz_title );
        }
        v3i( rlN_i5 );
        v3i( rlN_i0 );
        v3i( rlN_i3 );
        v3i( rlN_i4 );
    endpolygon();
    bgnpolygon();
        v3i( rlN_i4 );
        v3i( rlN_i3 );
        v3i( rlN_i2 );
        v3i( rlN_i6 );
    endpolygon();
    bgnpolygon();
        v3i( rlN_i4 );
        v3i( rlN_i6 );
        v3i( rlN_i7 );
        v3i( rlN_i5 );
    endpolygon();
    bgnpolygon();
        v3i( rlN_i0 );
        v3i( rlN_i1 );
        v3i( rlN_i2 );
        v3i( rlN_i3 );
    endpolygon();

}



/* 
 * this function should do whatever initialization is required 
 * so that the common parts of the 3d icon can just be called as objects
 */
void Doc_init( void  )
{
}


/* 
 * draw an instance of the 3d icon with the specified string
 * then dispose of the temporary objects
 */
void Doc_make( STRING Sz_title, int N_color )
{
	long N_id;
	
	N_id = genobj();
	makeobj( N_id );
        linewidth(1);
    
        pushmatrix();
            polymode( PYM_FILLNOUT );  /* for fill */
            color( N_color );
            buildDocument( Sz_title );
        popmatrix();
        
    closeobj();
	callobj( N_id );
	delobj( N_id );    
}

