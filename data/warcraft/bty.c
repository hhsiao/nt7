// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qing"}));        
        set("gender", "男性");                
        set("long", "一條龍[2;37;0m
它是北城雲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bty");
        set("owner_name", "北城雲");
        set_temp("owner", "bty");
        set_temp("owner_name", "北城雲");
        ::setup();
}
