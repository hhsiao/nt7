// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m埃其亞基[2;37;0m[2;37;0m", ({"ling_hu"}));        
        set("gender", "男性");                
        set("long", "這是一隻純白的老虎，在當地的語言中，它名字的意思是銀色的風。[2;37;0m
它是聶鋒的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "niefeng");
        set("owner_name", "聶鋒");
        set_temp("owner", "niefeng");
        set_temp("owner_name", "聶鋒");
        ::setup();
}
