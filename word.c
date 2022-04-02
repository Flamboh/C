#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 5

// Word list
char* words[] = { "pasta","taffy","flame","swoop","aloof","sight","broke","teary","chart","sixty","wordy","sheer","leper","nosey","savor","clamp","funky","foamy","toxic","brand","plumb","dingy","butte","drill","tripe","bicep","tenor","krill","worse","drama","hyena","think","ratio","cobra","basil","scrum","bused","phone","court","camel","proof","heard","angel","petal","pouty","throb","maybe","fetal","sprig","spine","shout","cadet","macro","dodgy","satyr","rarer","binge","trend","nutty","leapt","amiss","split","myrrh","width","sonar","tower","baron","fever","waver","spark","belie","sloop","expel","smote","baler","above","north","wafer","scant","frill","awash","snack","scowl","frail","drift","limbo","fence","motel","ounce","wreak","revel","talon","prior","knelt","cello","flake","debug","anode","crime","salve","scout","imbue","pinky","stave","vague","chock","fight","video","stone","teach","cleft","frost","prawn","booty","twist","apnea","stiff","plaza","ledge","tweak","board","grant","medic","bacon","cable","brawl","slunk","raspy","forum","drone","women","mucus","boast","toddy","coven","tumor","truer","wrath","stall","steam","axial","purer","daily","trail","niche","mealy","juice","nylon","plump","merry","flail","papal","wheat","berry","cower","erect","brute","leggy","snipe","sinew","skier","penny","jumpy","rally","umbra","scary","modem","gross","avian","greed","satin","tonic","parka","sniff","livid","stark","trump","giddy","reuse","taboo","avoid","quote","devil","liken","gloss","gayer","beret","noise","gland","dealt","sling","rumor","opera","thigh","tonga","flare","wound","white","bulky","etude","horse","circa","paddy","inbox","fizzy","grain","exert","surge","gleam","belle","salvo","crush","fruit","sappy","taker","tract","ovine","spiky","frank","reedy","filth","spasm","heave","mambo","right","clank","trust","lumen","borne","spook","sauce","amber","lathe","carat","corer","dirty","slyly","affix","alloy","taint","sheep","wooly","mauve","flung","yacht","fried","quail","brunt","grimy","curvy","cagey","rinse","deuce","state","grasp","milky","bison","graft","sandy","baste","flask","hedge","girly","swash","boney","coupe","endow","abhor","welch","blade","tight","geese","miser","mirth","cloud","cabal","leech","close","tenth","pecan","droit","grail","clone","guise","ralph","tango","biddy","smith","mower","payee","serif","drape","fifth","spank","glaze","allot","truck","kayak","virus","tepee","fully","zonal","metro","curry","grand","banjo","axion","bezel","occur","chain","nasal","gooey","filer","brace","allay","pubic","raven","plead","gnash","flaky","munch","dully","eking","thing","slink","hurry","theft","shorn","pygmy","ranch","wring","lemon","shore","mamma","froze","newer","style","moose","antic","drown","vegan","chess","guppy","union","lever","lorry","image","cabby","druid","exact","truth","dopey","spear","cried","chime","crony","stunk","timid","batch","gauge","rotor","crack","curve","latte","witch","bunch","repel","anvil","soapy","meter","broth","madly","dried","scene","known","magma","roost","woman","punch","pasty","downy","knead","whirl","rapid","clang","anger","drive","goofy","email","music","stuff","bleep","rider","mecca","folio","setup","verso","quash","fauna","gummy","happy","newly","fussy","relic","guava","ratty","fudge","femur","chirp","forte","alibi","whine","petty","golly","plait","fleck","felon","gourd","brown","thrum","ficus","stash","decry","wiser","junta","visor","daunt","scree","impel","await","press","whose","turbo","stoop","speak","mangy","eying","inlet","crone","pulse","mossy","staid","hence","pinch","teddy","sully","snore","ripen","snowy","attic","going","leach","mouth","hound","clump","tonal","bigot","peril","piece","blame","haute","spied","undid","intro","basal","shine","gecko","rodeo","guard","steer","loamy","scamp","scram","manly","hello","vaunt","organ","feral","knock","extra","condo","adapt","willy","polka","rayon","skirt","faith","torso","match","mercy","tepid","sleek","riser","twixt","peace","flush","catty","login","eject","roger","rival","untie","refit","aorta","adult","judge","rower","artsy","rural","shave","bobby","eclat","fella","gaily","harry","hasty","hydro","liege","octal","ombre","payer","sooth","unset","unlit","vomit" };


void emptyString(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        str[i] = '\0';
    }
}

void stringToLower(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int stringIsAlpha(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]))
            return 0;
    }
    return 1;
}


int main(void)
{
    // Determine random word
    srand(time(0));
    char* word = words[rand() % (sizeof(words) / sizeof(words[0]))];

    // Variables
    int guess_count = 0;
    char guess_progress[WORD_LENGTH + 1];
    for (int i = 0; i < WORD_LENGTH; i++) {
        guess_progress[i] = '-';
    }
    guess_progress[WORD_LENGTH] =  '\0';

    // Play game
    printf("I am thinking of a word -- you guess it. I will give you\nclues to help you get it. Good luck!!\n\n");
    printf("You are starting a new game...\n");
    while (1) {
        char guess_word[WORD_LENGTH + 1] = "";
        char* guessptr = guess_word;
        char common_letters[WORD_LENGTH + 1] = "";
        char* commonptr = common_letters;
        int matches = 0;
        while (strlen(guess_word) == 0) {
            printf("Guess a five letter word. ");
            scanf("%s", guess_word);
            stringToLower(guessptr);
            if (strchr(guess_word, '?') != NULL)
                break;
            else if (!stringIsAlpha(guessptr) || strlen(guess_word) != WORD_LENGTH) {
                emptyString(guessptr);
                printf("You must guess a five letter word. Start again.\n");
            }
        }
        guess_count += 1;
        if (strchr(guess_word, '?') != NULL) {
            printf("The secret word is %s\n", word);
            break;
        }
        else {
            emptyString(commonptr);
            matches = 0;
            for (int i = 0; i < WORD_LENGTH; i++) {
                for (int j = 0; j < WORD_LENGTH; j++) {
                    if (guess_word[i] == word[j]) {
                        matches += 1;
                        common_letters[strlen(common_letters)] = guess_word[i];
                        common_letters[strlen(common_letters)] = '\0';
                        if (i == j)
                            guess_progress[j] = guess_word[i];
                    }
                }

            }
            printf("There were %i matches and the commmon letters were...%s\n", matches, common_letters);
            printf("From the exact letter matches you know............%s\n", guess_progress);
            if (!strcmp(guess_word, word)) {
                printf("\nYou have guessed the word. It took %i guesses!\n", guess_count);
                break;
            }
            else if (matches == 0)
                printf("\nIf you give up, type '?' for you next guess.\n");
        }
    }
}
