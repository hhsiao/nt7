// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m路燈[2;37;0m[2;37;0m", ({"aiyuhs"}));        
        set("gender", "男性");                
        set("long", "我是照明的路燈，屬國家財產其他人等不得損壞。[2;37;0m
它是愛雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aiyu");
        set("owner_name", "愛雨");
        set_temp("owner", "aiyu");
        set_temp("owner_name", "愛雨");
        ::setup();
}
