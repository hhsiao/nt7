// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅牛[2;37;0m[2;37;0m", ({"doo"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是黑豬的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "dook");
        set("owner_name", "黑豬");
        set_temp("owner", "dook");
        set_temp("owner_name", "黑豬");
        ::setup();
}
