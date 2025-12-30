// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m咬一口[2;37;0m[2;37;0m", ({"qmhh"}));        
        set("gender", "男性");                
        set("long", "咬一口[2;37;0m
它是打狗幫主的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "qmh");
        set("owner_name", "打狗幫主");
        set_temp("owner", "qmh");
        set_temp("owner_name", "打狗幫主");
        ::setup();
}
