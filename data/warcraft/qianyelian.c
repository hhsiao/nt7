// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m觀音菩薩蓮臺[2;37;0m[2;37;0m", ({"guanyinliantai"}));        
        set("gender", "女性");                
        set("long", "$HIW$觀音菩薩蓮臺[2;37;0m
它是乾冶蓮的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianyelian");
        set("owner_name", "乾冶蓮");
        set_temp("owner", "qianyelian");
        set_temp("owner_name", "乾冶蓮");
        ::setup();
}
