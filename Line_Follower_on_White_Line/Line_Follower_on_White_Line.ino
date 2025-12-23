
/*
___________________________________________________________________________________________________________________________________________________________

This code is for a simple prototype Line Follower On a White line .
It was made by : Ahmed El-Nasri .
           At : 16  \  12  \  2025
Contact me :
  Linkdin  acc  : https://www.linkedin.com/in/ahmed-el-nasri-7952b0304?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app
  Facebook acc : https://www.facebook.com/ahmed.elnasri.54?mibextid=JRoKGi
  Gmail        : ahmedelnasri61@gmail.com

___________________________________________________________________________________________________________________________________________________________
*/


//________________________________ Line Follower _____________________________________
//       ______________________________________________________________________                
//              _______________________________________________________                
//                     _________________________________________                
//                           ___________________________                
//                                  _____________                
//                                     ______                
//                                       __                           

//Sensors
#define ir_1 2
#define ir_2 3
#define ir_3 4


//Motors
#define m_R1 5
#define m_R2 6
#define m_L1 7
#define m_L2 8

#define En_1 9
#define En_2 11

int last = 0 ; // forword >> 0 , left >> 1 ,  right >> 2                           .


void setup() {

  pinMode ( ir_1 , INPUT ) ;
  pinMode ( ir_2 , INPUT ) ;
  pinMode ( ir_3 , INPUT ) ;

  pinMode (  m_R1, OUTPUT ) ;
  pinMode (  m_R2, OUTPUT ) ;
  pinMode (  m_L1, OUTPUT ) ;
  pinMode (  m_L2, OUTPUT ) ;

  pinMode (  En_1, OUTPUT ) ;
  pinMode (  En_2, OUTPUT ) ;

  Serial.begin ( 9600 ) ;
  stop () ;
}


void loop() {
 int L = digitalRead ( ir_1 ) ;
 Serial.print ("  L  ");
 Serial.print ( L  );
 int C = digitalRead ( ir_2 ) ;
 Serial.print ( "   C " );
 Serial.print (  C);
 int R = digitalRead ( ir_3 ) ;
Serial.print ( "   R   "  );
Serial.println ( R  );

//     -----000-----
 if  ( !L && !C && !R )    { if ( last == 0 ) { stop (); } Serial.println( "  End of Track  "); }

//     -----100-----
 if  ( L && !C && !R )     { right (80) ; last = 2; Serial.println( "  Slow Right   ");}

//     -----010-----
 if  ( !L && C && !R )     { forword ( 80 ); last = 0; Serial.println( "  Slow forword ( OFF TRACK )   "); }

//     -----001-----
 if  ( !L && !C && R )     { left ( 80 ) ; last = 1; Serial.println( "  Slow Left   ");}

//     -----110-----
 if  ( L && C && !R )    { right ( 80 ) ; last = 2; Serial.println( "  Hard Right   "); }

//     -----101-----
 if  ( L && !C && R )      { forword ( 80 ) ; last = 0; Serial.println( " On The Line ");}

//     -----011-----
 if  ( !L && C && R )      { left ( 80 ) ; last = 1; Serial.println( "  Hard Left   ");}

//    -----111-----
if   ( L && C && R ) {
  if (last == 2)      { right(50);   }
  else if (last == 1) { left(50);    }
  else                { forword(50); }
  Serial.println(" OFF line - following memory ");
}

 delay ( 10 ) ;
 //stop ( ) ;

}

// functions

void forword ( int speed){
  analogWrite ( En_1 , speed ) ;
  analogWrite ( En_2 , speed ) ;

  digitalWrite ( m_R1 , 1 ) ;
  digitalWrite ( m_R2 , 0 ) ;
  digitalWrite ( m_L1 , 1 ) ;
  digitalWrite ( m_L2 , 0 ) ;
}

void right ( int speed ){
  analogWrite ( En_1 , 0 ) ;
  analogWrite ( En_2 , speed ) ;

  digitalWrite ( m_R1 , 1 ) ;
  digitalWrite ( m_R2 , 0 ) ;
  digitalWrite ( m_L1 , 1 ) ;
  digitalWrite ( m_L2 , 0 ) ;
}

void left ( int speed ){
  analogWrite ( En_1 , speed ) ;
  analogWrite ( En_2 , 0 ) ;

  digitalWrite ( m_R1 , 1 ) ;
  digitalWrite ( m_R2 , 0 ) ;
  digitalWrite ( m_L1 , 1 ) ;
  digitalWrite ( m_L2 , 0 ) ;
}

void stop (){
  analogWrite ( En_1 , 0 ) ;
  analogWrite ( En_2 , 0 ) ;  
  digitalWrite ( m_R1 , 0 ) ;
  digitalWrite ( m_R2 , 0 ) ;
  digitalWrite ( m_L1 , 0 ) ;
  digitalWrite ( m_L2 , 0 ) ;
}

