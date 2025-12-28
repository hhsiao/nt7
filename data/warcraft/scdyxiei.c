// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m伯虎[2;37;0m[2;37;0m", ({"iei"}));        
        set("gender", "女性");                
        set("long", "白色[2;37;0m
它是伯賞昆妤的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "scdyxiei");
        set("owner_name", "伯賞昆妤");
        set_temp("owner", "scdyxiei");
        set_temp("owner_name", "伯賞昆妤");
        ::setup();
}
