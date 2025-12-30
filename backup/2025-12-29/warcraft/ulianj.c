// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m墨魚[2;37;0m[2;37;0m", ({"mql"}));        
        set("gender", "男性");                
        set("long", "墨魚再臨[2;37;0m
它是鐵頭丙的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ulianj");
        set("owner_name", "鐵頭丙");
        set_temp("owner", "ulianj");
        set_temp("owner_name", "鐵頭丙");
        ::setup();
}
