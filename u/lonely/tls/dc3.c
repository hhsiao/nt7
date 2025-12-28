#include <ansi.h>
inherit ROOM;
string long_desc();
void create()
{
        set("short", GRN"點蒼十九峰"NOR);
        set("long", (: long_desc :));
        set("resource/water", 1);
        set("outdoors", "大理");
        set("exits", ([
              "westup"    : __DIR__"dc2",
              "southdown" : __DIR__"diancang",            
        ]));
        set("coor/x",-340);
  set("coor/y",-420);
   set("coor/z",0);
   setup();
}

string long_desc()
{
        string desc;

        switch( random(6) ) {
        case 0: desc = 
"點蒼山龍泉、玉局兩峰，峰勢平和，景色秀麗。峰中有‘龍泉’、
‘玉局’兩泉，泉水清澈甘甜，是泡茶上品。兩泉之水再加上山中無數小溪
水，成溪“綠玉”，流向大理城郊。\n";       
                break;
        case 1: desc =
"玉局、馬龍兩峰位於點蒼山東，峰上綠林滿覆，鳥獸出沒，一派生機
勃勃的景象。“龍溪”從半山腰飛瀑而下，落入一深潭之中，瀑聲若雷，宛
如龍吟。\n";               
                break;
        case 2: desc =
"馬龍、聖應峰山勢平坦，一溪曰“青碧”從中緩緩流出，於峰底平坡
上分為三條小溪，再又于山下‘聖應亭’側相匯流向大理城郊。\n";      
                break;
        case 3: desc =
"聖應、佛頂兩峰高矮相對，山間常年霧氣瀰漫，有如仙境。一溪流出，
名曰“莫殘”，盤盤轉轉十幾個彎後才向山下流去。\n";    
                break;
        case 4: desc =
"佛頂、馬耳兩峰形態怪異，峰中所生草木多為藥材，時常有大理城中
的採藥人來這裡採集名貴草藥。山上流下的“葶溟”溪據說也具奇效，常飲
百病不生、延年益壽。\n";      
                break;
        case 5: desc =
"點蒼山東馬耳、斜陽兩峰前後並立，登上峰頂後大理城全貌盡收眼底，
是遊人常來之地。“陽南”溪水從此流過，水流不急不緩，繞過山石流向大
理城郊。\n";       
                break;
        }

        return desc;
}