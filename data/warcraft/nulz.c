// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "在天的見證之下，集勇氣、智慧、;與美麗於一身的強大生物![2;37;0m
它是三文魚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nulz");
        set("owner_name", "三文魚");
        set_temp("owner", "nulz");
        set_temp("owner_name", "三文魚");
        ::setup();
}
