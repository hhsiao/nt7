// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m掩眼捕雀[2;37;0m[2;37;0m", ({"wbb"}));        
        set("gender", "男性");                
        set("long", "掩眼捕雀!!![2;37;0m
它是夜發的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wobb");
        set("owner_name", "夜發");
        set_temp("owner", "wobb");
        set_temp("owner_name", "夜發");
        ::setup();
}
