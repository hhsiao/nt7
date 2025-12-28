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
              "northup"  : __DIR__"dc1",
              "eastdown" : __DIR__"dc3",            
        ]));
        set("coor/x",-350);
  set("coor/y",-420);
   set("coor/z",10);
   setup();
}
string long_desc()
{
        string desc;

        switch( random(6) ) {
        case 0: desc =
"點蒼山西三陽、蘭峰兩峰，峰勢雄壯，險要之出不可勝數，且松林遍
布。人要上去，當真比登天還難。峰中一溪名曰“白石”，溪水色如白玉，
飛流直下。\n";        
                break;
        case 1: desc =
"點蒼山西蘭峰、雪人兩峰，一綠林滿覆，一冰雪籠罩，形神各異。峰
中冰雪溶水和天然山泉相匯，組成一到白簾瀑布，飛落直下，濺起陣陣水霧，
這便是有名的“雙鴛”溪。\n";               
                break;
        case 2: desc =
"點蒼山西雪人、應樂峰皆為高山雪峰。只見兩峰聳立，直衝雲霄，峰
上白雪層層覆蓋，在陽光照耀下顯得更加亮麗。冰雪溶水緩緩流下，一條條
小渠慢慢相匯，成一溪流名曰“隱仙”。\n";        
                break;
        case 3: desc =
"點蒼山西應樂、觀音兩峰高矮相對，加上山間雲霧繚繞，使之越發顯
得神秘，相傳觀世音菩薩曾親臨此地遊玩而不思歸去。峰間流淌的“梅溪”
得名於溪旁那一片天然梅林。\n";        
                break;
        case 4: desc =
"點蒼山西觀音、中和兩峰峰勢平和，峰中奇花異草繁多。而峰下桃樹
林更是一絕，遠遠望去，有如一片紅雲。“桃溪”從中淌過，帶著紅色的桃
花緩緩流下山去。\n";        
                break;
        case 5: desc =
"點蒼山西中和、龍泉兩峰氣侯溫和，乃是種植花草的理想之處。遠遠
可看見由大理花匠所開的一片片花圃，點點花紅撒落在兩峰之上。峰中“中
溪”流經之處更是花開似錦，美不勝收。\n";        
                break;
        }
        return desc;
}