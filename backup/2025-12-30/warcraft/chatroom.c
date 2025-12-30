// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "  [2;37;0m
它是杜不子騰的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "chatroom");
        set("owner_name", "杜不子騰");
        set_temp("owner", "chatroom");
        set_temp("owner_name", "杜不子騰");
        ::setup();
}
