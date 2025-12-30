// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "女性");                
        set("long", "在天的見證之下，集勇氣、智慧、與美麗於一身的強大生物![2;37;0m
它是三吻魚的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "nuli");
        set("owner_name", "三吻魚");
        set_temp("owner", "nuli");
        set_temp("owner_name", "三吻魚");
        ::setup();
}
