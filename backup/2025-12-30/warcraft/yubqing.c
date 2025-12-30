// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m玉字二號丸[2;37;0m[2;37;0m", ({"yqb"}));        
        set("gender", "男性");                
        set("long", "lkjjjjjjjjjjjjjj[2;37;0m
它是東方玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yubqing");
        set("owner_name", "東方玉");
        set_temp("owner", "yubqing");
        set_temp("owner_name", "東方玉");
        ::setup();
}
