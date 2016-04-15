
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "printf.h"
#include "ff.h"

#define CHAR_HEIGHT 6
#define CHAR_WIDTH  6
void init(void);
uint16_t x=8,y=(CHAR_HEIGHT+1)*2;
uint16_t px=190,py=125;
rectangle r;
void display_aperture();
void display_nuke();
void display_science();
//void display_pieces();
void display_cake();
void display_blackMesa();
void display_fire();
//void display_strange();
void display_happy4u();
void display_heart();
void display_gliph(char c);
FATFS FatFs;
FIL File;  						/* FAT File */
FIL File2;

int position = 0;
void print_delayed(char* str,uint8_t delay){
    uint8_t i=0;
    while(str[i]!='\0')
        {if(str[i]== '\n') {
            y+=CHAR_HEIGHT*2;
            x=8;
        }
         else
            {display_char_xy(str[i],x,y);
             x+=CHAR_WIDTH;
            }
         _delay_ms(delay);

         display_string_xy("_",x,y);
         _delay_ms(delay);
         r.bottom =y+6;
         r.top = y;
         r.left =x;
         r.right=x+5;
         fill_rectangle(r,BLACK);
         _delay_ms(delay);
        i++;}
}

void clean_main(){
    r.top=(CHAR_HEIGHT+1)*2;
    r.bottom=225;
    r.left=8;
    r.right=8+ (CHAR_WIDTH)*29;
    fill_rectangle(r,BLACK);
    x=8;
    y=(CHAR_HEIGHT+1)*2;
}

void clear_ascii(){
    r.left=px;
    r.right=320;
    r.top=py;
    r.bottom=240;
    fill_rectangle(r,BLACK);
}

void lyricDisplay(){
    f_mount(&FatFs, "", 0);

    if (f_open(&File, "lyrics.txt", FA_READ) == FR_OK) {
        char line[32];
        char delay[5];
        char buffer[11];
        int delayMS;
        uint8_t i;
        for(i=0;i<125;i++){
             f_gets (line, 30, &File);
             f_gets(delay,5,&File);
             f_gets(buffer,10,&File);
             delayMS= ((delay[1]-'0')*10 + (delay[2]-'0'))*10 + (delay[3]-'0');

             if(line[1] == ' ') print_delayed("\n",delayMS);
             else if(line[1] == '*')
                if( line[2] == ' ' ) clean_main();
                else if(line[2]== 't') _delay_ms(delayMS);
                    else display_gliph(line[2]);
             else
                {
                print_delayed(line ,delayMS);
                print_delayed("\n",1);
                }
             //f_lseek(&File, 30);
        }
        f_close(&File);
         print_delayed("Citit pozitie\n",10);
    } else {
        print_delayed("Test initiative unsuccesful \n",10);
    }
}

void main(void) {
    init();
    display_color(GOLD, BLACK);
    uint8_t i;
    display_string("------------------------------- ---------------------\n");
    display_string("\n");
    for(i=0;i<6;i++){
    display_string("|                              ||                   |\n");
    display_string("\n");
    }
    display_string("|                              ||_ _ _ _ _ _ _ _ _ _|\n");
    display_string("\n");
    for(i=0;i<6;i++){
    display_string("|                              |\n");
    display_string("\n");
    }
    display_string(" -------------------------------\n");
    lyricDisplay();
}

// For the good of all of us
// 30064 ms

void display_aperture(){
    clear_ascii();
    int tpy=py;
    display_ascii("	              .,-:;//;:=,              ",px,tpy+=5);
	display_ascii("          . :H@@@MM@M#H/.,+%;,          ",px,tpy+=5);
	display_ascii("       ,/X+ +M@@M@MM%=,-%HMMM@X/,       ",px,tpy+=5);
	display_ascii("     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-     ",px,tpy+=5);
	display_ascii("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.   ",px,tpy+=5);
	display_ascii("  ,%MM@@MH ,@%=            .---=-=:=,.  ",px,tpy+=5);
	display_ascii("  =@#@@@MX .,              -%HX$$%%%+;  ",px,tpy+=5);
	display_ascii(" =-./@M@M$                  .;@MMMM@MM: ",px,tpy+=5);
	display_ascii(" X@/ -$MM/                    .+MM@@@M$ ",px,tpy+=5);
	display_ascii(",@M@H: :@:                    . =X#@@@@-",px,tpy+=5);
	display_ascii(",@@@MMX, .                    /H- ;@M@M=",px,tpy+=5);
	display_ascii(".H@@@@M@+,                    %MM+..%#$.",px,tpy+=5);
	display_ascii(" /MMMM@MMH/.                  XM@MH; =; ",px,tpy+=5);
	display_ascii("  /%+%$XHH@$=              , .H@@@@MX,  ",px,tpy+=5);
	display_ascii("   .=--------.           -%H.,@@@@@MX,  ",px,tpy+=5);
	display_ascii("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%.   ",px,tpy+=5);
	display_ascii("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=     ",px,tpy+=5);
	display_ascii("       =%@M@M#@$-.=$@MM@@@M; %M%=       ",px,tpy+=5);
	display_ascii("         ,:+$+-,/H#MMMMMMM@= =,         ",px,tpy+=5);
	display_ascii("               =++%%%%+/:-.             ",px,tpy+=5);
}
void display_nuke(){
    clear_ascii();
    int tpy=py;
    display_ascii("             =+$HM####@H%;,             ",px,tpy+=5);
    display_ascii("          /H##############M$,           ",px,tpy+=5);
    display_ascii("          ,@################+           ",px,tpy+=5);
    display_ascii("           .H##############+            ",px,tpy+=5);
    display_ascii("             X############/             ",px,tpy+=5);
    display_ascii("              $##########/              ",px,tpy+=5);
    display_ascii("               %########/               ",px,tpy+=5);
    display_ascii("                /X/;;+X/                ",px,tpy+=10);
    display_ascii("                 -XHHX-                 ",px,tpy+=5);
    display_ascii("                ,######,                ",px,tpy+=5);
    display_ascii("#############X  .M####M.  X#############",px,tpy+=5);
    display_ascii("##############-   -//-   -##############",px,tpy+=5);
    display_ascii("X##############%,      ,+##############X",px,tpy+=5);
    display_ascii("-##############X        X##############-",px,tpy+=5);
    display_ascii(" %############%          %############% ",px,tpy+=5);
    display_ascii("  %##########;            ;##########%  ",px,tpy+=5);
    display_ascii("   ;#######M=              =M#######;   ",px,tpy+=5);
    display_ascii("    .+M###@,                ,@###M+.    ",px,tpy+=5);
    display_ascii("       :XH.                  .HX:       ",px,tpy+=5);
}
void display_science(){
    clear_ascii();
    int tpy=py;
    display_ascii("    	              =/;;/-                ",px,tpy+=5);
    display_ascii("	                +:    //                ",px,tpy+=5);
    display_ascii("	               /;      /;               ",px,tpy+=5);
    display_ascii("	              -X        H.              ",px,tpy+=5);
    display_ascii("	.//;;;:;;-,   X=        :+   .-;:=;:;%;.",px,tpy+=5);
    display_ascii("	M-       ,=;;;#:,      ,:#;;:=,       ,@",px,tpy+=5);
    display_ascii("	:%           :%.=/++++/=.$=           %=",px,tpy+=5);
    display_ascii("	 ,%;         %/:+/;,,/++:+/         ;+. ",px,tpy+=5);
    display_ascii("	   ,+/.    ,;@+,        ,%H;,    ,/+,   ",px,tpy+=5);
    display_ascii("	      ;+;;/= @.  .H##X   -X :///+;      ",px,tpy+=5);
    display_ascii("	      ;+=;;;.@,  .XM@$.  =X.//;=%/.     ",px,tpy+=5);
    display_ascii("	   ,;:      :@%=        =$H:     .+%-   ",px,tpy+=5);
    display_ascii("	 ,%=         %;-///==///-//         =%, ",px,tpy+=5);
    display_ascii("	;+           :%-;;;:;;;;-X-           +:",px,tpy+=5);
    display_ascii("	@-      .-;;;;M-        =M/;;;-.      -X",px,tpy+=5);
    display_ascii("	 :;;::;;-.    %-        :+    ,-;;-;:== ",px,tpy+=5);
    display_ascii("                      ,X        H.       ",px,tpy+=5);
    display_ascii("	               ;/      %=               ",px,tpy+=5);
    display_ascii("	                //    +;                ",px,tpy+=5);
    display_ascii("	                 ,////,                 ",px,tpy+=5);
}

void display_heart(){
    clear_ascii();
    int tpy=py;
    display_ascii(" 	                      .,---.         ",px,tpy+=5);
    display_ascii("	                        ,/XM#MMMX;,      ",px,tpy+=5);
    display_ascii("	                      -%##########M%,    ",px,tpy+=5);
    display_ascii("	                     -@######%  $###@=   ",px,tpy+=5);
    display_ascii("	      .,--,         -H#######$   $###M:  ",px,tpy+=5);
    display_ascii("	   ,;$M###MMX;     .;##########$;HM###X= ",px,tpy+=5);
    display_ascii("	 ,/@##########H=      ;################+ ",px,tpy+=5);
    display_ascii("	-+#############M/,      %##############+ ",px,tpy+=5);
    display_ascii("	%M###############=      /##############: ",px,tpy+=5);
    display_ascii("	H################      .M#############;. ",px,tpy+=5);
    display_ascii("	@###############M      ,@###########M:.  ",px,tpy+=5);
    display_ascii("	X################,      -$=X#######@:    ",px,tpy+=5);
    display_ascii("	/@##################%-     +######$-     ",px,tpy+=5);
    display_ascii("	.;##################X     .X#####+,      ",px,tpy+=5);
    display_ascii("	 .;H################/     -X####+.       ",px,tpy+=5);
    display_ascii("	   ,;X##############,       .MM/         ",px,tpy+=5);
    display_ascii("	      ,:+$H@M#######M#$-    .$$=         ",px,tpy+=5);
    display_ascii("	           .,-=;+$@###X:    ;/=.         ",px,tpy+=5);
    display_ascii("	                  .,/X$;   .::,          ",px,tpy+=5);
    display_ascii("	                      .,    ..           ",px,tpy+=5);
    display_ascii("                                          ",px,tpy+=5);

}/*
void display_pieces(){
    clear_ascii();
    int tpy=py;
    display_ascii("    	         .+                         ",px,tpy+=5);
    display_ascii("	             /M;                        ",px,tpy+=5);
    display_ascii("	              H#@:              ;,      ",px,tpy+=5);
    display_ascii("	               -###H-          -@/      ",px,tpy+=5);
    display_ascii("	               %####$.  -;  .%#X        ",px,tpy+=5);
    display_ascii("	                M#####+;#H :M#M.        ",px,tpy+=5);
    display_ascii("	..          .+/;%#########X###-         ",px,tpy+=5);
    display_ascii("	 -/%H%+;-,    +##############/          ",px,tpy+=5);
    display_ascii("	    .:$M###MH$%#############X  ,--=;-   ",px,tpy+=5);
    display_ascii("	        -/H#####################H+=.    ",px,tpy+=5);
    display_ascii("	           .+#################X.        ",px,tpy+=5);
    display_ascii("	         =%M####################H;.     ",px,tpy+=5);
    display_ascii("	            /@###############+;;/%%;,   ",px,tpy+=5);
    display_ascii("	         -%###################$.        ",px,tpy+=5);
    display_ascii("	       ;H######################M=       ",px,tpy+=5);
    display_ascii("	    ,%#####MH$%;+#####M###-/@####%      ",px,tpy+=5);
    display_ascii("	  :$H%+;=-      -####X.,H#   -+M##@-    ",px,tpy+=5);
    display_ascii("	 .              ,###;    ;      =$##+   ",px,tpy+=5);
    display_ascii("	                .#H,               :XH, ",px,tpy+=5);
    display_ascii("	                 +                   .;-",px,tpy+=5);
}*/
void display_fire(){
    clear_ascii();
    int tpy=py;
    display_ascii("                       -$-               ",px,tpy+=5);
    display_ascii("	                    .H##H,              ",px,tpy+=5);
    display_ascii("	                   +######+             ",px,tpy+=5);
    display_ascii("	                .+#########H.           ",px,tpy+=5);
    display_ascii("	              -$############@.          ",px,tpy+=5);
    display_ascii("	            =H###############@  -X:     ",px,tpy+=5);
    display_ascii("	          .$##################:  @#@-   ",px,tpy+=5);
    display_ascii("	     ,:  .M###################;  H###;  ",px,tpy+=5);
    display_ascii("	   ;@#:  @###################@  ,#####: ",px,tpy+=5);
    display_ascii("	 -M###.  M#################@.  ;######H ",px,tpy+=5);
    display_ascii("	 M####-  +###############$   =@#######X ",px,tpy+=5);
    display_ascii("	 H####$   -M###########+   :#########M, ",px,tpy+=5);
    display_ascii("	  /####X-   =########%   :M########@/.  ",px,tpy+=5);
    display_ascii("	    ,;%H@X;   .$###X   :##MM@%+;:-      ",px,tpy+=5);
    display_ascii("	                 ..                     ",px,tpy+=5);
    display_ascii("	  -/;:-,.              ,,-==+M########H ",px,tpy+=5);
    display_ascii("	 -##################@HX%%+%%$%%%+:,,    ",px,tpy+=5);
    display_ascii("	    .-/H%%%+%%$H@###############M@+=:/+:",px,tpy+=5);
    display_ascii("	/XHX%:#####MH%=    ,---:;;;;/%%XHM,:###$",px,tpy+=5);
    display_ascii("	$@#MX %+;-                           .	",px,tpy+=5);
}
void display_happy4u(){
    clear_ascii();
    int tpy=py;
	display_ascii("                                    :X- ",px,tpy+=5);
	display_ascii("                                 :X###  ",px,tpy+=5);
	display_ascii("                               ;@####@  ",px,tpy+=5);
	display_ascii("                             ;M######X  ",px,tpy+=5);
	display_ascii("                           -@########$  ",px,tpy+=5);
	display_ascii("                         .$##########@  ",px,tpy+=5);
	display_ascii("                        =M############- ",px,tpy+=5);
	display_ascii("                       +##############$ ",px,tpy+=5);
	display_ascii("                     .H############$=.  ",px,tpy+=5);
	display_ascii("         ,/:         ,M##########M;.    ",px,tpy+=5);
	display_ascii("      -+@###;       =##########M;       ",px,tpy+=5);
	display_ascii("   =%M#######;     :#########M/         ",px,tpy+=5);
	display_ascii("-$M###########;   :#########/           ",px,tpy+=5);
	display_ascii(" ,;X###########; =########$.            ",px,tpy+=5);
	display_ascii("     ;H#########+#######M=              ",px,tpy+=5);
	display_ascii("       ,+##############+                ",px,tpy+=5);
	display_ascii("          /M#########@-                 ",px,tpy+=5);
	display_ascii("            ;M######%                   ",px,tpy+=5);
	display_ascii("              +####:                    ",px,tpy+=5);
	display_ascii("               ,$M-                     ",px,tpy+=5);
}
void display_blackMesa(){
    clear_ascii();
    int tpy=py;
    display_ascii("             .-;+$XHHHHHHX$+;-.          \n",px,tpy+=5);
    display_ascii("         ,;X@@X%/;=----=:/%X@@X/         \n",px,tpy+=5);
    display_ascii("      =$@@%=.              .=+H@X:       \n",px,tpy+=5);
    display_ascii("     -XMX:                      =XMX=    \n",px,tpy+=5);
    display_ascii("    /@@:                          =H@+   \n",px,tpy+=5);
    display_ascii("   %@X,                            .$@$  \n",px,tpy+=5);
    display_ascii("  +@X.                               $@% \n",px,tpy+=5);
    display_ascii(" -@@,                                .@@=\n",px,tpy+=5);
    display_ascii(" %@%                                  +@$\n",px,tpy+=5);
    display_ascii(" H@:                                  :@H\n",px,tpy+=5);
    display_ascii(" H@:         :HHHHHHHHHHHHHHHHHHX,    =@H\n",px,tpy+=5);
    display_ascii(" %@%         ;@M@@@@@@@@@@@@@@@@@H-   +@$\n",px,tpy+=5);
    display_ascii(" =@@,        :@@@@@@@@@@@@@@@@@@@@@= .@@:\n",px,tpy+=5);
    display_ascii("  +@X        :@@@@@@@@@@@@@@@M@@@@@@:%@% \n",px,tpy+=5);
    display_ascii("   $@$,      ;@@@@@@@@@@@@@@@@@M@@@@@@$. \n",px,tpy+=5);
    display_ascii("    +@@HHHHHHH@@@@@@@@@@@@@@@@@@@@@@@+   \n",px,tpy+=5);
    display_ascii("     =X@@@@@@@@@@@@@@@@@@@@@@@@@@@@X=    \n",px,tpy+=5);
    display_ascii("       :$@@@@@@@@@@@@@@@@@@@M@@@@$:      \n",px,tpy+=5);
    display_ascii("         ,;$@@@@@@@@@@@@@@@@@@X/-        \n",px,tpy+=5);
    display_ascii("            .-;+$XXHHHHHX$+;-.           \n",px,tpy+=5);
}

void display_cake(){
    clear_ascii();
    int tpy=py;
	display_ascii("            ,:/+/-                       ",px,tpy+=5);
	display_ascii("            /M/              .,-=;//;-   ",px,tpy+=5);
	display_ascii("       .:/= ;MH/,    ,=/+%$XH@MM#@:      ",px,tpy+=5);
	display_ascii("      -$##@+$###@H@MMM#######H:.    -/H# ",px,tpy+=5);
	display_ascii(" .,H@H@ X######@ -H#####@+-     -+H###@X ",px,tpy+=5);
	display_ascii("  .,@##H;      +XM##M/,     =%@###@X;-   ",px,tpy+=5);
	display_ascii("X%-  :M##########$.    .:%M###@%:        ",px,tpy+=5);
	display_ascii("M##H,   +H@@@$/-.  ,;$M###@%,          - ",px,tpy+=5);
	display_ascii("M####M=,,---,.-%%H####M$:          ,+@## ",px,tpy+=5);
	display_ascii("@##################@/.         :%H##@$-  ",px,tpy+=5);
	display_ascii("M###############H,         ;HM##M$=      ",px,tpy+=5);
	display_ascii("#################.    .=$M##M$=          ",px,tpy+=5);
	display_ascii("################H..;XM##M$=          .:+ ",px,tpy+=5);
	display_ascii("M###################@%=           =+@MH% ",px,tpy+=5);
	display_ascii("@################M/.          =+H#X%=    ",px,tpy+=5);
	display_ascii("=+M##############M,       -/X#X+;.       ",px,tpy+=5);
	display_ascii("  .;XM##########H=    ,/X#H+:.           ",px,tpy+=5);
	display_ascii("     ,:/%XM####H/.                       ",px,tpy+=5);
	display_ascii("          ,.:=-.                         ",px,tpy+=5);
}/*
void display_strange(){
    clear_ascii();
    int tpy=py;
    display_ascii("        #+ @      # #              M#@   ",px,tpy+=5);
    display_ascii("	 .    .X  X.%##@;# #   +@#######X. @#%  ",px,tpy+=5);
    display_ascii("	   ,==.   ,######M+  -#####%M####M-    #",px,tpy+=5);
    display_ascii("	  :H##M%:=##+ .M##M,;#####/+#######% ,M#",px,tpy+=5);
    display_ascii("	 .M########=  -@#@.=#####M=M#######=  X#",px,tpy+=5);
    display_ascii("	 :@@MMM##M.  -##M.,#######M#######. =  M",px,tpy+=5);
    display_ascii("	             @##..###:.    .H####, @@ X,",px,tpy+=5);
    display_ascii("	   ############: ###,/####;  /##= @#. M ",px,tpy+=5);
    display_ascii("	           ,M## ;##,@#M;/M#M  @# X#% X# ",px,tpy+=5);
    display_ascii("	.%=   ######M## ##.M#:   ./#M ,M #M ,#$ ",px,tpy+=5);
    display_ascii("	##/         $## #+;#: #### ;#/ M M- @# :",px,tpy+=5);
    display_ascii("	#+ #M@MM###M-;M #:$#-##$H# .#X @ + $#. #",px,tpy+=5);
    display_ascii("	      ######/.: #%=# M#:MM./#.-#  @#: H#",px,tpy+=5);
    display_ascii("	+,.=   @###: /@ %#,@  ##@X #,-#@.##% .@#",px,tpy+=5);
    display_ascii("	#####+;/##/ @##  #@,+       /#M    . X, ",px,tpy+=5);
    display_ascii("	   ;###M#@ M###H .#M-     ,##M  ;@@; ###",px,tpy+=5);
    display_ascii("	   .M###%  ;####X ,@#######M/ -M###$  -H",px,tpy+=5);
    display_ascii("	    .M###%  X####H  .@@MM@;  ;@#M@      ",px,tpy+=5);
    display_ascii("	      H#M    /@####/      ,++.  / ==-,  ",px,tpy+=5);
    display_ascii("	               ,=/:, .+X@MMH@#H  #####$=",px,tpy+=5);
}*/

void display_gliph(char c){
    if(c == 'a') display_aperture();
    if(c == 'n') display_nuke();
    if(c == 's') display_science();
    //if(c == 'p') display_pieces();
    if(c == 'c') display_cake();
    if(c == 'b') display_blackMesa();
    if(c == 'f') display_fire();
    //if(c == 'S') display_strange();
    if(c == 'H') display_happy4u();
    if(c == 'h') display_heart();
}

void init(void) {
    /* 8MHz clock, no prescaling (DS, p. 48) */
    CLKPR = (1 << CLKPCE);
    CLKPR = 0;

    //LED init
    DDRB  |=  _BV(PB7);   /* LED pin out */
	PORTB &= ~_BV(PB7);   /* LED off */

    init_lcd();
}
