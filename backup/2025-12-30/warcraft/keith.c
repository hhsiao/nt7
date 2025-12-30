// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m風[1;33m淚[1;34m痕[2;37;0m[2;37;0m", ({"kkeith"}));        
        set("gender", "男性");                
        set("long", "風淚痕[2;37;0m
它是尚萬強的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "keith");
        set("owner_name", "尚萬強");
        set_temp("owner", "keith");
        set_temp("owner_name", "尚萬強");
        ::setup();
}
