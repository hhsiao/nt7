// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("毛頭[2;37;0m[2;37;0m", ({"help_nick"}));        
        set("gender", "女性");                
        set("long", "長得很難看[2;37;0m
它是西門捶血的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kamul");
        set("owner_name", "西門捶血");
        set_temp("owner", "kamul");
        set_temp("owner_name", "西門捶血");
        ::setup();
}
