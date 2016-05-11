#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "lcd.h"
#include "printf.h"
#include "ff.h"


#define CHAR_HEIGHT 6
#define CHAR_WIDTH  6

char* aperture[] PROGMEM ={
			"              .,-:;//;:=,               ",
			"          . :H@@@MM@M#H/.,+%;,          ",
			"       ,/X+ +M@@M@MM%=,-%HMMM@X/,       ",
			"     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-     ",
			"    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.   ",
			"  ,%MM@@MH ,@%=            .---=-=:=,.  ",
			"  =@#@@@MX .,              -%HX$$%%%+;  ",
			" =-./@M@M$                  .;@MMMM@MM: ",
			" X@/ -$MM/                    .+MM@@@M$ ",
			",@M@H: :@:                    . =X#@@@@-",
			",@@@MMX, .                    /H- ;@M@M=",
			".H@@@@M@+,                    %MM+..%#$.",
			" /MMMM@MMH/.                  XM@MH; =; ",
			"  /%+%$XHH@$=              , .H@@@@MX,  ",
			"   .=--------.           -%H.,@@@@@MX,  ",
			"   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%.   ",
			"     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=     ",
			"       =%@M@M#@$-.=$@MM@@@M; %M%=       ",
			"         ,:+$+-,/H#MMMMMMM@= =,         ",
			"               =++%%%%+/:-.             "
	};
char* cake[] PROGMEM = {
            "            ,:/+/-                       ",
            "            /M/              .,-=;//;-   ",
            "       .:/= ;MH/,    ,=/+%$XH@MM#@:      ",
            "      -$##@+$###@H@MMM#######H:.    -/H# ",
            " .,H@H@ X######@ -H#####@+-     -+H###@X ",
            "  .,@##H;      +XM##M/,     =%@###@X;-   ",
            "X%-  :M##########$.    .:%M###@%:        ",
            "M##H,   +H@@@$/-.  ,;$M###@%,          - ",
            "M####M=,,---,.-%%H####M$:          ,+@## ",
            "@##################@/.         :%H##@$-  ",
            "M###############H,         ;HM##M$=      ",
            "#################.    .=$M##M$=          ",
            "################H..;XM##M$=          .:+ ",
            "M###################@%=           =+@MH% ",
            "@################M/.          =+H#X%=    ",
            "=+M##############M,       -/X#X+;.       ",
            "  .;XM##########H=    ,/X#H+:.           ",
            "     ,:/%XM####H/.                       ",
            "          ,.:=-.                         ",
            "                                         "
    };
char* nuke[] PROGMEM = {
    "             =+$HM####@H%;,             ",
    "          /H##############M$,           ",
    "          ,@################+           ",
    "           .H##############+            ",
    "             X############/             ",
    "              $##########/              ",
    "               %########/               ",
    "                /X/;;+X/                ",
    "                                        ",
    "                 -XHHX-                 ",
    "                ,######,                ",
    "#############X  .M####M.  X#############",
    "##############-   -//-   -##############",
    "X##############%,      ,+##############X",
    "-##############X        X##############-",
    " %############%          %############% ",
    "  %##########;            ;##########%  ",
    "   ;#######M=              =M#######;   ",
    "    .+M###@,                ,@###M+.    ",
    "       :XH.                  .HX:       "
    };
/*char* strange[] PROGMEM ={
    "        #+ @      # #              M#@   ",
    "	 .    .X  X.%##@;# #   +@#######X. @#%  ",
    "	   ,==.   ,######M+  -#####%M####M-    #",
    "	  :H##M%:=##+ .M##M,;#####/+#######% ,M#",
    "	 .M########=  -@#@.=#####M=M#######=  X#",
    "	 :@@MMM##M.  -##M.,#######M#######. =  M",
    "	             @##..###:.    .H####, @@ X,",
    "	   ############: ###,/####;  /##= @#. M ",
    "	           ,M## ;##,@#M;/M#M  @# X#% X# ",
    "	.%=   ######M## ##.M#:   ./#M ,M #M ,#$ ",
    "	##/         $## #+;#: #### ;#/ M M- @# :",
    "	#+ #M@MM###M-;M #:$#-##$H# .#X @ + $#. #",
    "	      ######/.: #%=# M#:MM./#.-#  @#: H#",
    "	+,.=   @###: /@ %#,@  ##@X #,-#@.##% .@#",
    "	#####+;/##/ @##  #@,+       /#M    . X, ",
    "	   ;###M#@ M###H .#M-     ,##M  ;@@; ###",
    "	   .M###%  ;####X ,@#######M/ -M###$  -H",
    "	    .M###%  X####H  .@@MM@;  ;@#M@      ",
    "	      H#M    /@####/      ,++.  / ==-,  ",
    "	               ,=/:, .+X@MMH@#H  #####$="
    };*/
char* science[] PROGMEM = {
    "    	              =/;;/-                ",
    "	                +:    //                ",
    "	               /;      /;               ",
    "	              -X        H.              ",
    "	.//;;;:;;-,   X=        :+   .-;:=;:;%;.",
    "	M-       ,=;;;#:,      ,:#;;:=,       ,@",
    "	:%           :%.=/++++/=.$=           %=",
    "	 ,%;         %/:+/;,,/++:+/         ;+. ",
    "	   ,+/.    ,;@+,        ,%H;,    ,/+,   ",
    "	      ;+;;/= @.  .H##X   -X :///+;      ",
    "	      ;+=;;;.@,  .XM@$.  =X.//;=%/.     ",
    "	   ,;:      :@%=        =$H:     .+%-   ",
    "	 ,%=         %;-///==///-//         =%, ",
    "	;+           :%-;;;:;;;;-X-           +:",
    "	@-      .-;;;;M-        =M/;;;-.      -X",
    "	 :;;::;;-.    %-        :+    ,-;;-;:== ",
    "                      ,X        H.         ",
    "	               ;/      %=               ",
    "	                //    +;                ",
    "	                 ,////,                 "
    };
char* blackMesa[] PROGMEM ={
    "             .-;+$XHHHHHHX$+;-.          \n",
    "         ,;X@@X%/;=----=:/%X@@X/         \n",
    "      =$@@%=.              .=+H@X:       \n",
    "     -XMX:                      =XMX=    \n",
    "    /@@:                          =H@+   \n",
    "   %@X,                            .$@$  \n",
    "  +@X.                               $@% \n",
    " -@@,                                .@@=\n",
    " %@%                                  +@$\n",
    " H@:                                  :@H\n",
    " H@:         :HHHHHHHHHHHHHHHHHHX,    =@H\n",
    " %@%         ;@M@@@@@@@@@@@@@@@@@H-   +@$\n",
    " =@@,        :@@@@@@@@@@@@@@@@@@@@@= .@@:\n",
    "  +@X        :@@@@@@@@@@@@@@@M@@@@@@:%@% \n",
    "   $@$,      ;@@@@@@@@@@@@@@@@@M@@@@@@$. \n",
    "    +@@HHHHHHH@@@@@@@@@@@@@@@@@@@@@@@+   \n",
    "     =X@@@@@@@@@@@@@@@@@@@@@@@@@@@@X=    \n",
    "       :$@@@@@@@@@@@@@@@@@@@M@@@@$:      \n",
    "         ,;$@@@@@@@@@@@@@@@@@@X/-        \n",
    "            .-;+$XXHHHHHX$+;-.           \n",
    };
char* heart[] PROGMEM ={
    "                             .,---.         ",
    "	                        ,/XM#MMMX;,      ",
    "	                      -%##########M%,    ",
    "	                     -@######%  $###@=   ",
    "	      .,--,         -H#######$   $###M:  ",
    "	   ,;$M###MMX;     .;##########$;HM###X= ",
    "	 ,/@##########H=      ;################+ ",
    "	-+#############M/,      %##############+ ",
    "	%M###############=      /##############: ",
    "	H################      .M#############;. ",
    "	@###############M      ,@###########M:.  ",
    "	X################,      -$=X#######@:    ",
    "	/@##################%-     +######$-     ",
    "	.;##################X     .X#####+,      ",
    "	 .;H################/     -X####+.       ",
    "	   ,;X##############,       .MM/         ",
    "	      ,:+$H@M#######M#$-    .$$=         ",
    "	           .,-=;+$@###X:    ;/=.         ",
    "	                  .,/X$;   .::,          ",
    "	                      .,    ..           ",
    "                                            ",
    };
char* happy4u[] PROGMEM ={
    "                                    :X- ",
	"                                 :X###  ",
	"                               ;@####@  ",
	"                             ;M######X  ",
	"                           -@########$  ",
	"                         .$##########@  ",
	"                        =M############- ",
	"                       +##############$ ",
	"                     .H############$=.  ",
	"         ,/:         ,M##########M;.    ",
	"      -+@###;       =##########M;       ",
	"   =%M#######;     :#########M/         ",
	"-$M###########;   :#########/           ",
	" ,;X###########; =########$.            ",
	"     ;H#########+#######M=              ",
	"       ,+##############+                ",
	"          /M#########@-                 ",
	"            ;M######%                   ",
	"              +####:                    ",
	"               ,$M-                     "
    };
char* fire[] PROGMEM ={
    "                       -$-                 ",
    "	                    .H##H,              ",
    "	                   +######+             ",
    "	                .+#########H.           ",
    "	              -$############@.          ",
    "	            =H###############@  -X:     ",
    "	          .$##################:  @#@-   ",
    "	     ,:  .M###################;  H###;  ",
    "	   ;@#:  @###################@  ,#####: ",
    "	 -M###.  M#################@.  ;######H ",
    "	 M####-  +###############$   =@#######X ",
    "	 H####$   -M###########+   :#########M, ",
    "	  /####X-   =########%   :M########@/.  ",
    "	    ,;%H@X;   .$###X   :##MM@%+;:-      ",
    "	                 ..                     ",
    "	  -/;:-,.              ,,-==+M########H ",
    "	 -##################@HX%%+%%$%%%+:,,    ",
    "	    .-/H%%%+%%$H@###############M@+=:/+:",
    "	/XHX%:#####MH%=    ,---:;;;;/%%XHM,:###$",
    "	$@#MX %+;-                           .	"
    };
    /*
char* pieces[] PROGMEM ={
    "    	         .+                         ",
    "	             /M;                        ",
    "	              H#@:              ;,      ",
    "	               -###H-          -@/      ",
    "	               %####$.  -;  .%#X        ",
    "	                M#####+;#H :M#M.        ",
    "	..          .+/;%#########X###-         ",
    "	 -/%H%+;-,    +##############/          ",
    "	    .:$M###MH$%#############X  ,--=;-   ",
    "	        -/H#####################H+=.    ",
    "	           .+#################X.        ",
    "	         =%M####################H;.     ",
    "	            /@###############+;;/%%;,   ",
    "	         -%###################$.        ",
    "	       ;H######################M=       ",
    "	    ,%#####MH$%;+#####M###-/@####%      ",
    "	  :$H%+;=-      -####X.,H#   -+M##@-    ",
    "	 .              ,###;    ;      =$##+   ",
    "	                .#H,               :XH, ",
    "	                 +                   .;-",
    };*/
void init(void);
//Setup top of the main panel
uint16_t x=8,y=(CHAR_HEIGHT+1)*2;
uint16_t px=190,py=125;
uint16_t position = 0;

rectangle r;

//Gliph methods
void display_aperture();
void display_nuke();
void display_science();
//void display_pieces();progm
void display_cake();
void display_blackMesa();
void display_fire();
//void display_strange();
void display_happy4u();
void display_heart();

//Central gliph method
void display_background();
void display_gliph(char c);

FATFS FatFs;                    /* File System */
FIL File;  						/* FAT File */

//Displays text with a given delay between letters
//Also blinks the "_"
void print_delayed(char* str,uint8_t delay){
    uint8_t i=0;
    char lastChr = 0;

    while(str[i]!='\0'){
        //Avoids printing spaces at the end of the line
        if(lastChr != 0 && lastChr == str[i] && lastChr == ' ')
            str[i+1]='\0';
        lastChr = str[i];

        if(str[i]== '\n') {             //Newline handling
            y+=CHAR_HEIGHT*2;
            x=8;
        }
        else{
            display_char_xy(str[i],x,y);
             x+=CHAR_WIDTH;             //Next letter placement
            }
         _delay_ms(delay);

         display_string_xy("_",x,y);    //Underline blinking
         _delay_ms(delay);

         r.top = y;                    //Setup cleaning rectangle
         r.bottom =y+CHAR_HEIGHT;
         r.left =x;
         r.right=x+CHAR_WIDTH -1;

         fill_rectangle(r,BLACK);      //Fill the rectangle
         _delay_ms(delay);
        i++;}
}

//Clears the main display window
void clean_main(){
    r.top=(CHAR_HEIGHT+1)*2;    //Setup and fill rectangle
    r.bottom=225;
    r.left=8;
    r.right=8+ (CHAR_WIDTH)*29;

    fill_rectangle(r,BLACK);

    //Reset the positions for printing
    x=8;
    y=(CHAR_HEIGHT+1)*2;
}

//Clear the gliph display window
void clear_ascii(){
    r.top=py;                   //Setup and fill rectangle
    r.bottom=240;
    r.left=px;
    r.right=320;

    fill_rectangle(r,BLACK);
}

//Reads lyrics from the "lyrics.txt" text file on the FAT FS
void lyricDisplay(){
    f_mount(&FatFs, "", 0);
    if (f_open(&File, "lyrics.txt", FA_READ) == FR_OK) {
        char line[32];
        char delay[5];
        char buffer[11];
        int delayMS;
        uint8_t i;
        for(i=0;i<130;i++){
             f_gets (line, 30, &File);
             f_gets(delay,5,&File);
             f_gets(buffer,5,&File);
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
    } else {
        print_delayed("Test initiative unsuccesful \n",10);
    }
}

void main(void) {
    init();

    //Display background
    display_color(GOLD, BLACK);
    display_background();

    /*
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
    */
    //Start displaying lyrics
    lyricDisplay();
}


void display_background(){
    uint8_t i,j;
    for(i=0;i<31;i++)
        display_string("-");
    display_string(" ");
    for(i=0;i<21;i++)
        display_string("-");
    display_string("\n\n");

    for(i=0;i<6;i++){
        display_string("|");
        for(j=0;j<30;j++)
            display_string(" ");
        display_string("||");
        for(j=0;j<19;j++)
            display_string(" ");
        display_string("|\n\n");
    }
    display_string("|");
    for(j=0;j<30;j++)
            display_string(" ");
    display_string("||_ _ _ _ _ _ _ _ _ _|\n\n");

    for(i=0;i<6;i++){
        display_string("|");
        for(j=0;j<30;j++)
                display_string(" ");
        display_string("|\n\n");
        }

    display_string(" ");
    for(j=0;j<31;j++)
                display_string("-");
    display_string("\n");

}
void display_aperture(){
    clear_ascii();
    int tpy=py;

    display_ascii(aperture[0],px,tpy+=5);
    display_ascii(aperture[1],px,tpy+=5);
    display_ascii(aperture[2],px,tpy+=5);
    display_ascii(aperture[3],px,tpy+=5);
    display_ascii(aperture[4],px,tpy+=5);
    display_ascii(aperture[5],px,tpy+=5);
    display_ascii(aperture[6],px,tpy+=5);
    display_ascii(aperture[7],px,tpy+=5);
    display_ascii(aperture[8],px,tpy+=5);
    display_ascii(aperture[9],px,tpy+=5);
    display_ascii(aperture[10],px,tpy+=5);
    display_ascii(aperture[11],px,tpy+=5);
    display_ascii(aperture[12],px,tpy+=5);
    display_ascii(aperture[13],px,tpy+=5);
    display_ascii(aperture[14],px,tpy+=5);
    display_ascii(aperture[15],px,tpy+=5);
    display_ascii(aperture[16],px,tpy+=5);
    display_ascii(aperture[17],px,tpy+=5);
    display_ascii(aperture[18],px,tpy+=5);
    display_ascii(aperture[19],px,tpy+=5);

}
void display_nuke(){
    clear_ascii();
    int tpy=py;
    display_ascii(nuke[0],px,tpy+=5);
    display_ascii(nuke[1],px,tpy+=5);
    display_ascii(nuke[2],px,tpy+=5);
    display_ascii(nuke[3],px,tpy+=5);
    display_ascii(nuke[4],px,tpy+=5);
    display_ascii(nuke[5],px,tpy+=5);
    display_ascii(nuke[6],px,tpy+=5);
    display_ascii(nuke[7],px,tpy+=5);
    display_ascii(nuke[8],px,tpy+=5);
    display_ascii(nuke[9],px,tpy+=5);
    display_ascii(nuke[10],px,tpy+=5);
    display_ascii(nuke[11],px,tpy+=5);
    display_ascii(nuke[12],px,tpy+=5);
    display_ascii(nuke[13],px,tpy+=5);
    display_ascii(nuke[14],px,tpy+=5);
    display_ascii(nuke[15],px,tpy+=5);
    display_ascii(nuke[16],px,tpy+=5);
    display_ascii(nuke[17],px,tpy+=5);
    display_ascii(nuke[18],px,tpy+=5);
    display_ascii(nuke[19],px,tpy+=5);

}
void display_science(){
    clear_ascii();
    int tpy=py;

    display_ascii(science[0],px,tpy+=5);
    display_ascii(science[1],px,tpy+=5);
    display_ascii(science[2],px,tpy+=5);
    display_ascii(science[3],px,tpy+=5);
    display_ascii(science[4],px,tpy+=5);
    display_ascii(science[5],px,tpy+=5);
    display_ascii(science[6],px,tpy+=5);
    display_ascii(science[7],px,tpy+=5);
    display_ascii(science[8],px,tpy+=5);
    display_ascii(science[9],px,tpy+=5);
    display_ascii(science[10],px,tpy+=5);
    display_ascii(science[11],px,tpy+=5);
    display_ascii(science[12],px,tpy+=5);
    display_ascii(science[13],px,tpy+=5);
    display_ascii(science[14],px,tpy+=5);
    display_ascii(science[15],px,tpy+=5);
    display_ascii(science[16],px,tpy+=5);
    display_ascii(science[17],px,tpy+=5);
    display_ascii(science[18],px,tpy+=5);
    display_ascii(science[19],px,tpy+=5);

}
void display_heart(){
    clear_ascii();
    int tpy=py;
display_ascii(heart[0],px,tpy+=5);
    display_ascii(heart[1],px,tpy+=5);
    display_ascii(heart[2],px,tpy+=5);
    display_ascii(heart[3],px,tpy+=5);
    display_ascii(heart[4],px,tpy+=5);
    display_ascii(heart[5],px,tpy+=5);
    display_ascii(heart[6],px,tpy+=5);
    display_ascii(heart[7],px,tpy+=5);
    display_ascii(heart[8],px,tpy+=5);
    display_ascii(heart[9],px,tpy+=5);
    display_ascii(heart[10],px,tpy+=5);
    display_ascii(heart[11],px,tpy+=5);
    display_ascii(heart[12],px,tpy+=5);
    display_ascii(heart[13],px,tpy+=5);
    display_ascii(heart[14],px,tpy+=5);
    display_ascii(heart[15],px,tpy+=5);
    display_ascii(heart[16],px,tpy+=5);
    display_ascii(heart[17],px,tpy+=5);
    display_ascii(heart[18],px,tpy+=5);
    display_ascii(heart[19],px,tpy+=5);
}
/*
void display_pieces(){
    clear_ascii();
    int tpy=py;
    display_ascii(pieces[0],px,tpy+=5);
    display_ascii(pieces[1],px,tpy+=5);
    display_ascii(pieces[2],px,tpy+=5);
    display_ascii(pieces[3],px,tpy+=5);
    display_ascii(pieces[4],px,tpy+=5);
    display_ascii(pieces[5],px,tpy+=5);
    display_ascii(pieces[6],px,tpy+=5);
    display_ascii(pieces[7],px,tpy+=5);
    display_ascii(pieces[8],px,tpy+=5);
    display_ascii(pieces[9],px,tpy+=5);
    display_ascii(pieces[10],px,tpy+=5);
    display_ascii(pieces[11],px,tpy+=5);
    display_ascii(pieces[12],px,tpy+=5);
    display_ascii(pieces[13],px,tpy+=5);
    display_ascii(pieces[14],px,tpy+=5);
    display_ascii(pieces[15],px,tpy+=5);
    display_ascii(pieces[16],px,tpy+=5);
    display_ascii(pieces[17],px,tpy+=5);
    display_ascii(pieces[18],px,tpy+=5);
    display_ascii(pieces[19],px,tpy+=5);
}
*/
void display_fire(){
    clear_ascii();
    int tpy=py;

    display_ascii(fire[0],px,tpy+=5);
    display_ascii(fire[1],px,tpy+=5);
    display_ascii(fire[2],px,tpy+=5);
    display_ascii(fire[3],px,tpy+=5);
    display_ascii(fire[4],px,tpy+=5);
    display_ascii(fire[5],px,tpy+=5);
    display_ascii(fire[6],px,tpy+=5);
    display_ascii(fire[7],px,tpy+=5);
    display_ascii(fire[8],px,tpy+=5);
    display_ascii(fire[9],px,tpy+=5);
    display_ascii(fire[10],px,tpy+=5);
    display_ascii(fire[11],px,tpy+=5);
    display_ascii(fire[12],px,tpy+=5);
    display_ascii(fire[13],px,tpy+=5);
    display_ascii(fire[14],px,tpy+=5);
    display_ascii(fire[15],px,tpy+=5);
    display_ascii(fire[16],px,tpy+=5);
    display_ascii(fire[17],px,tpy+=5);
    display_ascii(fire[18],px,tpy+=5);
    display_ascii(fire[19],px,tpy+=5);
}
void display_happy4u(){
    clear_ascii();
    int tpy=py;

    display_ascii(happy4u[0],px,tpy+=5);
    display_ascii(happy4u[1],px,tpy+=5);
    display_ascii(happy4u[2],px,tpy+=5);
    display_ascii(happy4u[3],px,tpy+=5);
    display_ascii(happy4u[4],px,tpy+=5);
    display_ascii(happy4u[5],px,tpy+=5);
    display_ascii(happy4u[6],px,tpy+=5);
    display_ascii(happy4u[7],px,tpy+=5);
    display_ascii(happy4u[8],px,tpy+=5);
    display_ascii(happy4u[9],px,tpy+=5);
    display_ascii(happy4u[10],px,tpy+=5);
    display_ascii(happy4u[11],px,tpy+=5);
    display_ascii(happy4u[12],px,tpy+=5);
    display_ascii(happy4u[13],px,tpy+=5);
    display_ascii(happy4u[14],px,tpy+=5);
    display_ascii(happy4u[15],px,tpy+=5);
    display_ascii(happy4u[16],px,tpy+=5);
    display_ascii(happy4u[17],px,tpy+=5);
    display_ascii(happy4u[18],px,tpy+=5);
    display_ascii(happy4u[19],px,tpy+=5);

}
void display_blackMesa(){
    clear_ascii();
    int tpy=py;
     display_ascii(blackMesa[0],px,tpy+=5);
     display_ascii(blackMesa[1],px,tpy+=5);
    display_ascii(blackMesa[2],px,tpy+=5);
    display_ascii(blackMesa[3],px,tpy+=5);
    display_ascii(blackMesa[4],px,tpy+=5);
    display_ascii(blackMesa[5],px,tpy+=5);
    display_ascii(blackMesa[6],px,tpy+=5);
    display_ascii(blackMesa[7],px,tpy+=5);
    display_ascii(blackMesa[8],px,tpy+=5);
    display_ascii(blackMesa[9],px,tpy+=5);
    display_ascii(blackMesa[10],px,tpy+=5);
    display_ascii(blackMesa[11],px,tpy+=5);
    display_ascii(blackMesa[12],px,tpy+=5);
    display_ascii(blackMesa[13],px,tpy+=5);
    display_ascii(blackMesa[14],px,tpy+=5);
    display_ascii(blackMesa[15],px,tpy+=5);
    display_ascii(blackMesa[16],px,tpy+=5);
    display_ascii(blackMesa[17],px,tpy+=5);
    display_ascii(blackMesa[18],px,tpy+=5);
    display_ascii(blackMesa[19],px,tpy+=5);
}
void display_cake(){
    clear_ascii();
    int tpy=py;
	display_ascii(cake[0],px,tpy+=5);
    display_ascii(cake[1],px,tpy+=5);
    display_ascii(cake[2],px,tpy+=5);
    display_ascii(cake[3],px,tpy+=5);
    display_ascii(cake[4],px,tpy+=5);
    display_ascii(cake[5],px,tpy+=5);
    display_ascii(cake[6],px,tpy+=5);
    display_ascii(cake[7],px,tpy+=5);
    display_ascii(cake[8],px,tpy+=5);
    display_ascii(cake[9],px,tpy+=5);
    display_ascii(cake[10],px,tpy+=5);
    display_ascii(cake[11],px,tpy+=5);
    display_ascii(cake[12],px,tpy+=5);
    display_ascii(cake[13],px,tpy+=5);
    display_ascii(cake[14],px,tpy+=5);
    display_ascii(cake[15],px,tpy+=5);
    display_ascii(cake[16],px,tpy+=5);
    display_ascii(cake[17],px,tpy+=5);
    display_ascii(cake[18],px,tpy+=5);
    display_ascii(cake[19],px,tpy+=5);
}
/*
void display_strange(){
    clear_ascii();
    int tpy=py;

    display_ascii(strange[0],px,tpy+=5);
    display_ascii(strange[1],px,tpy+=5);
    display_ascii(strange[2],px,tpy+=5);
    display_ascii(strange[3],px,tpy+=5);
    display_ascii(strange[4],px,tpy+=5);
    display_ascii(strange[5],px,tpy+=5);
    display_ascii(strange[6],px,tpy+=5);
    display_ascii(strange[7],px,tpy+=5);
    display_ascii(strange[8],px,tpy+=5);
    display_ascii(strange[9],px,tpy+=5);
    display_ascii(strange[10],px,tpy+=5);
    display_ascii(strange[11],px,tpy+=5);
    display_ascii(strange[12],px,tpy+=5);
    display_ascii(strange[13],px,tpy+=5);
    display_ascii(strange[14],px,tpy+=5);
    display_ascii(strange[15],px,tpy+=5);
    display_ascii(strange[16],px,tpy+=5);
    display_ascii(strange[17],px,tpy+=5);
    display_ascii(strange[18],px,tpy+=5);
    display_ascii(strange[19],px,tpy+=5);
}
*/
void display_gliph(char c){
    /*
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
    */

    switch(c) {
      case 'a' :
         display_aperture(); break;
      case 'n' :
          display_nuke();break;
      case 's' :
         display_science(); break;
      case 'c' :
         display_cake();break;
      case 'b' :
         display_blackMesa();break;
     case 'f' :
         display_fire();break;
     case 'H' :
        display_happy4u();break;
     case 'h' :
        display_heart();break;
      default :
         break;
   }
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
