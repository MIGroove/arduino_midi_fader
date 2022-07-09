#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE(); 
void setup() {
  MIDI.begin(1);

}
void loop() {

int A0tmp = 0;
int A1tmp = 0;
int A2tmp = 0;


while(true){
  
     int A0Value = analogRead(A0);
     int A1Value = analogRead(A1);
     int A2Value = analogRead(A2);

     int Slot0 = map(A0Value , 0, 1023, 0, 127) ;
     int Slot1 = map(A1Value , 0, 1023, 0, 127) ;
     int Slot2 = map(A2Value , 0, 1023, 0, 127) ;

     
   //Refarence:MIDI.sendControlChange (DataByte inControlNumber , DataByte inControlValue , Channel inChannel )
   //Assignable controls CC slots (14-31) 

//ループ前と同一の値のCCが入力されたとき、CCの出力をしない
  if (A0tmp !=Slot0){
    MIDI.sendControlChange (1, Slot0 ,1);
      A0tmp= Slot0;
  }
  if (A1tmp !=Slot1){
    MIDI.sendControlChange (11, Slot1 ,1);
      A1tmp= Slot1;
  }
  if (A2tmp !=Slot2){
    MIDI.sendControlChange (21, Slot2 ,1);
      A2tmp= Slot2;
  }

      
      
  }

}

     
