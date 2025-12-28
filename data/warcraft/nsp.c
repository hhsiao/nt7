// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[1;37m[2;37;0m[2;37;0m", ({"ssl"}));        
        set("gender", "女性");                
        set("long", "mlm[2;37;0m
它是小號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nsp");
        set("owner_name", "小號");
        set_temp("owner", "nsp");
        set_temp("owner_name", "小號");
        ::setup();
}
