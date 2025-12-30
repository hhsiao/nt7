// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m金翅大鵬鳥[2;37;0m[2;37;0m", ({"hots"}));        
        set("gender", "女性");                
        set("long", "dfd[2;37;0m
它是樂橙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hot");
        set("owner_name", "樂橙");
        set_temp("owner", "hot");
        set_temp("owner_name", "樂橙");
        ::setup();
}
