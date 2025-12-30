// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m蒼[1;31m炎[2;37;0m[2;37;0m", ({"rat"}));        
        set("gender", "男性");                
        set("long", "神獸[2;37;0m
它是風之痕的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "freng");
        set("owner_name", "風之痕");
        set_temp("owner", "freng");
        set_temp("owner_name", "風之痕");
        ::setup();
}
