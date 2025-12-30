// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m小飛[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是雲卷的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yunj");
        set("owner_name", "雲卷");
        set_temp("owner", "yunj");
        set_temp("owner_name", "雲卷");
        ::setup();
}
