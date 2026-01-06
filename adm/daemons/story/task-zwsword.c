#include <ansi.h>
int give_gift();
mixed *story =
({
    "華山之巔，雲霧旋繞、仙氣升騰。",
    "【泥潭公告】華山長老風清揚決定與武當始祖張三丰於猴年馬月雞日豬時",
    "            舉行華山論劍，一決高下！",
    "風清揚傲然說道：“念你是武當始祖的份上，且讓你先出招！”",
    "張三丰面色由紅變紫，唰的一聲抽出寒光閃閃的"HIC"真武劍"NOR + WHT"，道：“那我就不",
    "客氣了！”",
    "張三丰使出太極劍法「纏」字訣，連遞數個虛招企圖擾亂風清揚的攻勢。",
    "風清揚hoho的奸笑了兩聲。",
    "風清揚舉劍畫弧，默潛獨孤九劍之「破式總訣」, 綿綿劍意，漫天鋪地襲",
    "向張三丰。",
    "張三丰頓時覺得眼前一花，手腕一麻，手中"HIC"真武劍"NOR + WHT"脫手而出！",
    (: give_gift :),
    "“啊！啊！！這……這怎麼可能？？？”張三丰大叫。",
    "風清揚收回風泉寶劍，看著面紅耳赤的張三丰，說：“ben，我就等著你",
    "出劍，是不是很後悔啊，乖，別哭，等下給你買棒棒糖……嘿嘿……"
});

void create() {
    seteuid(getuid());
}

mixed query_story_message(int step) {
    return step < sizeof(story) ? story[step] : 0;
}

int give_gift() {
    STORY_D->give_gift("/task/story/zwsword", 1,
        HIM "\n一把藍幽幽的"HIC"真武劍"HIM"從天而降，擦過你的鼻尖，\n"
        +"深深地插入你腳邊的泥土裡，把你嚇出一身冷汗。\n" NOR);
    return 1;
}
