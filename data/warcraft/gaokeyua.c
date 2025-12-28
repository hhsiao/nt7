// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小鳥鳥[2;37;0m[2;37;0m", ({"xiaoniao"}));        
        set("gender", "男性");                
        set("long", "其實我很大[2;37;0m
它是鳥米的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gaokeyua");
        set("owner_name", "鳥米");
        set_temp("owner", "gaokeyua");
        set_temp("owner_name", "鳥米");
        ::setup();
}
