// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m歐西里斯[2;37;0m[2;37;0m", ({"osiris"}));        
        set("gender", "男性");                
        set("long", "天空龍[2;37;0m
它是北宮凡的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "dqw");
        set("owner_name", "北宮凡");
        set_temp("owner", "dqw");
        set_temp("owner_name", "北宮凡");
        ::setup();
}
