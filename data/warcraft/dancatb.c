// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m大鵬[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "大鵬[2;37;0m
它是彈彈的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dancatb");
        set("owner_name", "彈彈");
        set_temp("owner", "dancatb");
        set_temp("owner_name", "彈彈");
        ::setup();
}
