// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m銅[1;35m板[1;35m[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "男性");                
        set("long", "長得好像飛毯一樣的銅板[2;37;0m
它是賈富貴的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xjia");
        set("owner_name", "賈富貴");
        set_temp("owner", "xjia");
        set_temp("owner_name", "賈富貴");
        ::setup();
}
