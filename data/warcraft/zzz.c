// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[45;1m墮落獨角獸[2;37;0m[2;37;0m", ({"mengyan"}));        
        set("gender", "男性");                
        set("long", "夢魘獸[2;37;0m
它是夢魘的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zzz");
        set("owner_name", "夢魘");
        set_temp("owner", "zzz");
        set_temp("owner_name", "夢魘");
        ::setup();
}
