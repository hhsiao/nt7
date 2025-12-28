// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小青[2;37;0m[2;37;0m", ({"xql"}));        
        set("gender", "男性");                
        set("long", "身似長蛇麒麟首鯉魚尾面有長鬚犄角似鹿有五爪相貌威武[2;37;0m
它是獨孤飛虹的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lhr");
        set("owner_name", "獨孤飛虹");
        set_temp("owner", "lhr");
        set_temp("owner_name", "獨孤飛虹");
        ::setup();
}
