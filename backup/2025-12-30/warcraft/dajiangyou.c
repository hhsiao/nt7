// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("醬油瓶[2;37;0m[2;37;0m", ({"djy"}));        
        set("gender", "男性");                
        set("long", "醬油瓶[2;37;0m
它是打醬油的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dajiangyou");
        set("owner_name", "打醬油");
        set_temp("owner", "dajiangyou");
        set_temp("owner_name", "打醬油");
        ::setup();
}
