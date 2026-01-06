#include <ansi.h>
int give_gift();
mixed *story =
({
    "一天，韋小寶收到老孃發來的E-mail：",
    "“小寶啊，最近生意不好啊，怎麼如今的男人對女人不感興趣了？”",
    "小寶想了想，跑去找康熙，說如此如此……",
    "康熙：你？不會吧，打死我也不信你會對女人沒興趣。",
    "小寶：哎呀不是我啦，是老孃也就是你弟弟我的兄弟的外甥的舅媽",
    "      開的麗春院最近沒什麼生意啊！",
    "康熙：恩？有這種事？好，最近吳三桂那小子運了一批從天竺進口的",
    "      XX藥，我就御賜給你，以解燃眉之急。",
    "小寶大喜，摟著康熙的肩膀：好小子，夠朋友，我這就差人給老孃送",
    "去啦！",
    "小寶一陣旋風似的飛出宮門。",
    "康熙笑了沒多久，忽然想起來，大驚失色：",
    "天啊，晚上我怎麼辦？",
    "………………",
    (: give_gift :)
});

void create() {
    seteuid(getuid());
}

mixed query_story_message(int step) {
    return step < sizeof(story) ? story[step] : 0;
}

int give_gift() {
    STORY_D->give_gift("/task/story/mcyao", 1,
        HIM "\n小寶趕到你面前，對你說：就拜託你啦！\n\n" NOR);
    return 0;
}
