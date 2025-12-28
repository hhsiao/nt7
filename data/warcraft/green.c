// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m琉璃虎[2;37;0m[2;37;0m", ({"gtiger"}));        
        set("gender", "男性");                
        set("long", "這是一隻白虎，身上有淺灰色的花紋，是一種珍稀幻獸。[2;37;0m
它是黃迦藍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "green");
        set("owner_name", "黃迦藍");
        set_temp("owner", "green");
        set_temp("owner_name", "黃迦藍");
        ::setup();
}
