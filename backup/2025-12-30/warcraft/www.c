// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[42;1m[1;33m銳金之氣[2;37;0m[2;37;0m", ({"x_hu"}));        
        set("gender", "男性");                
        set("long", "這是西方七宿之首白虎[2;37;0m
它是歐陽奇的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "www");
        set("owner_name", "歐陽奇");
        set_temp("owner", "www");
        set_temp("owner_name", "歐陽奇");
        ::setup();
}
