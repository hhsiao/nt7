// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老老老白虎[2;37;0m[2;37;0m", ({"tigersoul"}));        
        set("gender", "女性");                
        set("long", "老老老白虎[2;37;0m
它是甲打雜的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ipxa");
        set("owner_name", "甲打雜");
        set_temp("owner", "ipxa");
        set_temp("owner_name", "甲打雜");
        ::setup();
}
