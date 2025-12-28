// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("門口吊刀[2;37;0m[2;37;0m", ({"finger"}));        
        set("gender", "男性");                
        set("long", "門口吊刀，刀倒吊著[2;37;0m
它是刀倒吊著的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sixmai");
        set("owner_name", "刀倒吊著");
        set_temp("owner", "sixmai");
        set_temp("owner_name", "刀倒吊著");
        ::setup();
}
