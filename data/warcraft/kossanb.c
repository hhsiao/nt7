// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m米貳兵散[2;37;0m[2;37;0m", ({"kossanbpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是散兵貳米的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kossanb");
        set("owner_name", "散兵貳米");
        set_temp("owner", "kossanb");
        set_temp("owner_name", "散兵貳米");
        ::setup();
}
