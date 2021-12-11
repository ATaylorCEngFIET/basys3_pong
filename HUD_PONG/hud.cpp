#include "hud.h"
#include "char.h"


void hud_gen(axis& op, int row, int column, int char_1, int char_2) {
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=char_1
#pragma HLS INTERFACE s_axilite port=char_2
#pragma HLS INTERFACE s_axilite port=column
#pragma HLS INTERFACE s_axilite port=row
#pragma HLS INTERFACE axis register both port=op
#define max_scale 5
int i = 0;
int y = 0;
int x = 0;
int frm_lines =0;
int line = 0;
int pixel = 0;
int count_line = 0;
int count_pixel = 0;
int line_2 = 0;
int pixel_2 = 0;
int count_line_2 = 0;
int count_pixel_2 = 0;
extern int display_0[11][10];
extern int display_1[11][10];
extern int display_2[11][10];
extern int display_3[11][10];
extern int display_4[11][10];
extern int display_5[11][10];
extern int display_6[11][10];
extern int display_7[11][10];
extern int display_8[11][10];
extern int display_9[11][10];

video_stream hud_int;

	row_loop:for (y =0; y<row; y++){

		 column_loop:for (x =0; x <  column; x++) {
			 if (y == 0 && x == 0 ){
				 hud_int.user = 1;
			 }
			 else{
				 if (x == (column-1) ){
					 hud_int.last = 1;
				 }
				 else{
					 hud_int.last = 0;
					 hud_int.user = 0;

					 if ((y > 10 & y < 15 ) ){   //| ( y >(row-15) & y < (row-10))
						 if (x > 10 & x<(column-10)){
							 hud_int.data = 0x7f0000ff;
							 line = 0;
							 count_line  =0;
							 count_pixel =0;
							 pixel =0;
							 line_2 = 0;
							 count_line_2  =0;
							 count_pixel_2 =0;
							 pixel_2 =0;
						 }
						 else{
							 hud_int.data = 0;
						 }
					 }
					 else{
						 if(x>10 & x < 15){
							 hud_int.data = 0x7f0000ff;
						 }
						 else{
							 if (x>column-15 & x<column-10){
								 hud_int.data = 0x7f0000ff;

							 }
							 else{
								 if((y>row/2) & (y<((row/2)+110))){
									 if(x>29 & x <80){ //130
										 if (char_1 == 0){
											 hud_int.data = display_0[line][pixel];
										 } else if (char_1 == 1){
											 hud_int.data = display_1[line][pixel];
										 } else if (char_1 == 2){
											 hud_int.data = display_2[line][pixel];
										 } else if (char_1 == 3){
											 hud_int.data = display_3[line][pixel];
										 } else if (char_1 == 4){
											 hud_int.data = display_4[line][pixel];
										 } else if (char_1 == 5){
											 hud_int.data = display_5[line][pixel];
										 } else if (char_1 == 6){
											 hud_int.data = display_6[line][pixel];
										 } else if (char_1 == 7){
											 hud_int.data = display_7[line][pixel];
										 } else if (char_1 == 8){
											 hud_int.data = display_8[line][pixel];
										 } else if (char_1 == 9){
											 hud_int.data = display_9[line][pixel];
										 } else {
											 hud_int.data = display_0[line][pixel];
										 }

										 if (count_pixel == max_scale){
											 if (pixel == max_scale & count_line == max_scale){
												 count_line = 0;
												 pixel = 0;
												 count_pixel = 0;
												 line++;
											 } else {
												 if(pixel == max_scale & count_line <max_scale){
													 count_line++;
													 pixel = 0;
													 count_pixel = 0;
												 }else{
													 count_pixel = 0;
													 pixel++;
												 }

											 }
										 }
										 else{
											 count_pixel++;
										 }
									 }
									 else{
										 if(x>149 & x <200){ //250
											 if (char_2 == 0){
												 hud_int.data = display_0[line_2][pixel_2];
											 } else if (char_2 == 1){
												 hud_int.data = display_1[line_2][pixel_2];
											 } else if (char_2 == 2){
												 hud_int.data = display_2[line_2][pixel_2];
											 } else if (char_2 == 3){
												 hud_int.data = display_3[line_2][pixel_2];
											 } else if (char_2 == 4){
												 hud_int.data = display_4[line_2][pixel_2];
											 } else if (char_2 == 5){
												 hud_int.data = display_5[line_2][pixel_2];
											 } else if (char_2 == 6){
												 hud_int.data = display_6[line_2][pixel_2];
											 } else if (char_2 == 7){
												 hud_int.data = display_7[line_2][pixel_2];
											 } else if (char_2 == 8){
												 hud_int.data = display_8[line_2][pixel_2];
											 } else if (char_2 == 9){
												 hud_int.data = display_9[line_2][pixel_2];
											 } else {
												 hud_int.data = display_0[line_2][pixel_2];
											 }
											 if (count_pixel_2 == max_scale){
												 if (pixel_2 == max_scale & count_line_2 == max_scale){
													 count_line_2 = 0;
													 pixel_2 = 0;
													 count_pixel_2 = 0;
													 line_2++;
												 } else {
													 if(pixel_2 == max_scale & count_line_2 <max_scale){
														 count_line_2++;
														 pixel_2 = 0;
														 count_pixel_2 = 0;
													 }else{
														 count_pixel_2 = 0;
														 pixel_2++;
													 }

												 }
											 }
											 else{
												 count_pixel_2++;
											 }
										 }
										 else{
											 hud_int.data = 0;
										 }

									 }
								 }
								 else{
								 hud_int.data = 0;
								 }

							 }

						 }

					 }

				 }
			 }

			 op.write(hud_int);
		 }
	 }

}



