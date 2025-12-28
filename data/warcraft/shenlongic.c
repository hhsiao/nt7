// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神龍爾爾[2;37;0m[2;37;0m", ({"shenlongbbb"}));        
        set("gender", "男性");                
        set("long", "神龍爾爾[2;37;0m
它是神龍號二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shenlongic");
        set("owner_name", "神龍號二");
        set_temp("owner", "shenlongic");
        set_temp("owner_name", "神龍號二");
        ::setup();
}
