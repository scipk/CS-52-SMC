// Name : Your First Name & Last Name
// SSID : Student ID Number
// Assignment #: 3
// Submission Date : 4/18/2022
//
// Description : A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain the codebook characters
//
// command line arguments
// A03. exe configuration_filename . config - the name of the configuration file

# include < iostream > // std :: cout , std :: cin , etc.
# include < cstdlib > //C++ version of stdlib .h
# include < cstring > //C++ version of string .h
# include < string > //C++ string class
# include < fstream > //C++ file I/O using streams

constexpr auto CODE_BOOK_LENGTH = 64; //# define CODEBOOK 64 CBL

// struct to store the configuration
struct configuration {
    int k = 0;
    std :: string config_filename = "";
    std :: string codebook_filename = "";
    std :: string infile = "";
    std :: string outfile = "";
    bool encrypt = true ;
};

// A2 - Encrypt / Decrypt Functions with two additional parameters
void encrypt ( std :: string & plaintext , int k , char codebook [] , int codebook_length );
void decrypt ( std :: string & ciphertext , int k , char codebook [] , int codebook_length );

// A3 functions as described in this handout
void parse_config_file ( Configuration & c );
void read_codebook ( Configuration & c , char codebook [] , int length );
void read_input_file ( std :: string & msg , const Configuration & c );
void write_outfile ( std :: string & msg , const Configuration & c );

int main (int argc , char * argv [])
{
    // A3 Step 0: delcare a configuration struct
    configuration configuration;

    //
    // A3 Step 1: Use the command line arguments
    // to get the configuration file name from argv [1]
    
    // ensure argv [1] exists
    
    // then assign argv [1] to the configuration . config_filename

    //
    // A3 Step 2: declare a codebook array
    //
    char codebook [ CODE_BOOK_LENGTH ];

    // A3 Step 3: Parse the configuration file to initialize the configuration struct
    parse_config_file ( configuration );

    // A3 Step 4: initialize the codebook array with characters from the codebook . csv file
    read_codebook ( configuration , codebook , CODE_BOOK_LENGTH );

    // A2: string used to store plaintext or ciphertext
    std :: string msg ;

    // A3 Step 5: read in -i file specified in the configuration and store string in msg
    read_input_file ( msg , configuration );

    // A3 save the original message before encrypting or decrypting
    std :: string original_msg = msg ;

    //
    // A3 step 6: add codebook and length of codebook (64) to encrypt and decrypt functions
    // no other change should be needed to these A2 functions

    // If -E option is in the config file , encrypt the msg
    if ( configuration . encrypt )
    encrypt ( msg , configuration .k , codebook , CODE_BOOK_LENGTH );
    // If -D option is in the config file , decrypt the msg
    else
    decrypt ( msg , configuration .k , codebook , CODE_BOOK_LENGTH ); // decrypt ciphertext

    //
    // A3 Step 7: write out the string msg to the -o outfile
    //
    write_outfile ( msg , configuration );

    // From A2: Print out original msg and either ciphertext or plaintext
    // no change from assignment 2
    std :: cout << " enter any key to exit ";
    char c ; std :: cin >> c ;
    return 0;
}