// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "男性");                
        set("long", "玄武[2;37;0m
它是煉丁的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "liandand");
        set("owner_name", "煉丁");
        set_temp("owner", "liandand");
        set_temp("owner_name", "煉丁");
        ::setup();
}
