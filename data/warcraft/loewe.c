// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("法拉利[2;37;0m[2;37;0m", ({"falali"}));        
        set("gender", "男性");                
        set("long", "這是法拉利的進口車廠法拉利於2014年推出的一款跑車Ferrari F150[2;37;0m
它是愛尚汽車的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "loewe");
        set("owner_name", "愛尚汽車");
        set_temp("owner", "loewe");
        set_temp("owner_name", "愛尚汽車");
        ::setup();
}
