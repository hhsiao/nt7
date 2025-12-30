// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m東海三太子[2;37;0m[2;37;0m", ({"whitedragon"}));        
        set("gender", "男性");                
        set("long", "小白龍[2;37;0m
它是艾葉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aioria");
        set("owner_name", "艾葉");
        set_temp("owner", "aioria");
        set_temp("owner_name", "艾葉");
        ::setup();
}
