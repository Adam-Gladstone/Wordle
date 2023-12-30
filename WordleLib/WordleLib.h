#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <string>
#include <string_view>

#include <array>
#include <utility>


namespace wordle {

    using namespace std::literals;

    // Maximum word length supported
    static constexpr std::size_t length = 5;

    // Maximum number of words in the collection
    static constexpr std::size_t count = 463;

    constexpr std::array<std::string_view, count> words
    {
        "avoid"sv,"award"sv,"aware"sv,"badly"sv,"baker"sv,"bases"sv,"basic"sv,"basis"sv,"beach"sv,"began"sv,
        "begin"sv,"begun"sv,"being"sv,"below"sv,"bench"sv,"billy"sv,"birth"sv,"black"sv,"blame"sv,"blind"sv,
        "block"sv,"blood"sv,"board"sv,"boost"sv,"booth"sv,"bound"sv,"brain"sv,"brand"sv,"bread"sv,"break"sv,
        "breed"sv,"brief"sv,"bring"sv,"broad"sv,"broke"sv,"brown"sv,"build"sv,"built"sv,"buyer"sv,"cable"sv,
        "calif"sv,"carry"sv,"catch"sv,"cause"sv,"chain"sv,"chair"sv,"chart"sv,"chase"sv,"cheap"sv,"check"sv,
        "chest"sv,"chief"sv,"child"sv,"china"sv,"chose"sv,"civil"sv,"claim"sv,"class"sv,"clean"sv,"clear"sv,
        "click"sv,"clock"sv,"close"sv,"coach"sv,"coast"sv,"could"sv,"count"sv,"court"sv,"cover"sv,"craft"sv,
        "crash"sv,"cream"sv,"crime"sv,"cross"sv,"crowd"sv,"crown"sv,"curve"sv,"cycle"sv,"daily"sv,"dance"sv,
        "dated"sv,"dealt"sv,"death"sv,"debut"sv,"delay"sv,"depth"sv,"doing"sv,"doubt"sv,"dozen"sv,"draft"sv,
        "drama"sv,"drawn"sv,"dream"sv,"dress"sv,"drill"sv,"drink"sv,"drive"sv,"drove"sv,"dying"sv,"eager"sv,
        "early"sv,"earth"sv,"eight"sv,"elite"sv,"empty"sv,"enemy"sv,"enjoy"sv,"enter"sv,"entry"sv,"equal"sv,
        "error"sv,"event"sv,"every"sv,"exact"sv,"exist"sv,"extra"sv,"faith"sv,"false"sv,"fault"sv,"fiber"sv,
        "field"sv,"fifth"sv,"fifty"sv,"fight"sv,"final"sv,"first"sv,"fixed"sv,"flash"sv,"fleet"sv,"floor"sv,
        "fluid"sv,"focus"sv,"force"sv,"forth"sv,"forty"sv,"forum"sv,"found"sv,"frame"sv,"frank"sv,"fraud"sv,
        "fresh"sv,"front"sv,"fruit"sv,"fully"sv,"funny"sv,"giant"sv,"given"sv,"glass"sv,"globe"sv,"going"sv,
        "grace"sv,"grade"sv,"grand"sv,"grant"sv,"grass"sv,"great"sv,"green"sv,"gross"sv,"group"sv,"grown"sv,
        "guard"sv,"guess"sv,"guest"sv,"guide"sv,"happy"sv,"harry"sv,"heart"sv,"heavy"sv,"hence"sv,"henry"sv,
        "horse"sv,"hotel"sv,"house"sv,"human"sv,"ideal"sv,"image"sv,"index"sv,"inner"sv,"input"sv,"issue"sv,
        "japan"sv,"jimmy"sv,"joint"sv,"jones"sv,"judge"sv,"known"sv,"label"sv,"large"sv,"laser"sv,"later"sv,
        "laugh"sv,"layer"sv,"learn"sv,"lease"sv,"least"sv,"leave"sv,"legal"sv,"level"sv,"lewis"sv,"light"sv,
        "limit"sv,"links"sv,"lives"sv,"local"sv,"logic"sv,"loose"sv,"lower"sv,"lucky"sv,"lunch"sv,"lying"sv,
        "magic"sv,"major"sv,"maker"sv,"march"sv,"maria"sv,"match"sv,"maybe"sv,"mayor"sv,"meant"sv,"media"sv,
        "metal"sv,"might"sv,"minor"sv,"minus"sv,"mixed"sv,"model"sv,"money"sv,"month"sv,"moral"sv,"motor"sv,
        "mount"sv,"mouse"sv,"mouth"sv,"movie"sv,"music"sv,"needs"sv,"never"sv,"newly"sv,"night"sv,"noise"sv,
        "north"sv,"noted"sv,"novel"sv,"nurse"sv,"occur"sv,"ocean"sv,"offer"sv,"often"sv,"order"sv,"other"sv,
        "ought"sv,"paint"sv,"panel"sv,"paper"sv,"party"sv,"peace"sv,"peter"sv,"phase"sv,"phone"sv,"photo"sv,
        "piece"sv,"pilot"sv,"pitch"sv,"place"sv,"plain"sv,"plane"sv,"plant"sv,"plate"sv,"point"sv,"pound"sv,
        "power"sv,"press"sv,"price"sv,"pride"sv,"prime"sv,"print"sv,"prior"sv,"prize"sv,"proof"sv,"proud"sv,
        "prove"sv,"queen"sv,"quick"sv,"quiet"sv,"quite"sv,"radio"sv,"raise"sv,"range"sv,"rapid"sv,"ratio"sv,
        "reach"sv,"ready"sv,"refer"sv,"right"sv,"rival"sv,"river"sv,"robin"sv,"roger"sv,"roman"sv,"rough"sv,
        "round"sv,"route"sv,"royal"sv,"rural"sv,"scale"sv,"scene"sv,"scope"sv,"score"sv,"sense"sv,"serve"sv,
        "seven"sv,"shall"sv,"shape"sv,"share"sv,"sharp"sv,"sheet"sv,"shelf"sv,"shell"sv,"shift"sv,"shirt"sv,
        "shock"sv,"shoot"sv,"short"sv,"shown"sv,"sight"sv,"since"sv,"sixth"sv,"sixty"sv,"sized"sv,"skill"sv,
        "sleep"sv,"slide"sv,"small"sv,"smart"sv,"smile"sv,"smith"sv,"smoke"sv,"solid"sv,"solve"sv,"sorry"sv,
        "sound"sv,"south"sv,"space"sv,"spare"sv,"speak"sv,"speed"sv,"spend"sv,"spent"sv,"split"sv,"spoke"sv,
        "sport"sv,"staff"sv,"stage"sv,"stake"sv,"stand"sv,"start"sv,"state"sv,"steam"sv,"steel"sv,"stick"sv,
        "still"sv,"stock"sv,"stone"sv,"stood"sv,"store"sv,"storm"sv,"story"sv,"strip"sv,"stuck"sv,"study"sv,
        "stuff"sv,"style"sv,"sugar"sv,"suite"sv,"super"sv,"sweet"sv,"table"sv,"taken"sv,"taste"sv,"taxes"sv,
        "teach"sv,"teeth"sv,"terry"sv,"texas"sv,"thank"sv,"theft"sv,"their"sv,"theme"sv,"there"sv,"these"sv,
        "thick"sv,"thing"sv,"think"sv,"third"sv,"those"sv,"three"sv,"threw"sv,"throw"sv,"tight"sv,"times"sv,
        "tired"sv,"title"sv,"today"sv,"topic"sv,"total"sv,"touch"sv,"tough"sv,"tower"sv,"track"sv,"trade"sv,
        "train"sv,"treat"sv,"trend"sv,"trial"sv,"tried"sv,"tries"sv,"truck"sv,"truly"sv,"trust"sv,"truth"sv,
        "twice"sv,"under"sv,"undue"sv,"union"sv,"unity"sv,"until"sv,"upper"sv,"upset"sv,"urban"sv,"usage"sv,
        "usual"sv,"valid"sv,"value"sv,"video"sv,"virus"sv,"visit"sv,"vital"sv,"voice"sv,"waste"sv,"watch"sv,
        "water"sv,"wheel"sv,"where"sv,"which"sv,"while"sv,"white"sv,"whole"sv,"whose"sv,"woman"sv,"women"sv,
        "world"sv,"worry"sv,"worse"sv,"worst"sv,"worth"sv,"would"sv,"wound"sv,"write"sv,"wrong"sv,"wrote"sv,
        "yield"sv,"young"sv,"youth"sv,
    };

    enum class result {
        grey,           // incorrect letter
        orange,         // correct letter, incorrect position
        green           // correct letter, correct position
    };

    using result_item = std::pair<result, std::string_view>;

    // Determine if the input word is valid
    constexpr auto is_valid(std::string_view word) -> bool
    {
        if (word.size() != length)
            return false;

        // https://www.techiedelight.com/check-if-an-element-exists-in-an-array-cpp/
        return std::find(std::begin(words), std::end(words), word) != std::end(words);
    }

    struct result_values
    {
        static constexpr std::array<result_item, 3> values
        {
            {
                { result::grey, "Grey"sv },
                { result::orange, "Orange"sv },
                { result::green, "Green"sv }
            }
        };
    };

    // Retrieve a result string from a result
    constexpr auto result_string(result in) -> std::string_view
    {
        for (const auto& v : result_values::values)
        {
            if (v.first == in)
            {
                return v.second;
            }
        }
        return {};
    }

    // Generate an index value between 1 and max
    /*constexpr*/ auto get_index([[maybe_unused]] std::size_t max) -> std::size_t;

    // Select a word at random from the collection
    constexpr auto select_word(std::size_t index) -> std::string_view
    {
        return words.at(index);
    }

    // Report the result (grey, orange, green) for each character position in the user's guess
    auto report(std::string_view input_word, std::string_view target_word) -> std::array<result, length>;

    // Determine if the result is green in all positions
    auto is_win(const std::array<result, length>& results) -> bool;
}

