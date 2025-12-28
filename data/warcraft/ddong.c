// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"bhu"}));        
        set("gender", "女性");                
        set("long", "白虎[2;37;0m
它是董東的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ddong");
        set("owner_name", "董東");
        set_temp("owner", "ddong");
        set_temp("owner_name", "董東");
        ::setup();
}
