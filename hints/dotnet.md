.NET Core
=========

## Opening VS Code via the terminal
[I answered this question on stack overflow](https://stackoverflow.com/questions/973561/starting-visual-studio-from-a-command-prompt/52119741#52119741)

tl;dr:

For Visual Studio on a mac, you can:

```Shell
open '/Applications/Visual Studio.app' [path_to].sln
```

I create an alias in my bash_profile so I can just navigate to a directory and open it in VS:

```Shell
echo "alias vs=\"open '/Applications/Visual Studio.app' *.sln\"" >> ~/.bash_profile
```

## Creating a new API with Solution

```Shell
# Create the API project
dotnet new webapi -lang C# -n [ApiName]

# Create the DB Migrations project
dotnet new classlib -lang C# -n Migrations

# Create the solution
dotnet new sln -n [SolutionName]

# Setup FluentMigrator
cd Migrations
dotnet tool install -g FluentMigrator.DotNet.Cli
dotnet add package FluentMigrator
dotnet add package FluentMigrator.Runner
dotnet add package FluentMigrator.Runner.SqlServer
# dotnet add package Microsoft.Data.SqlLite
cd ../ # assumes this takes you to the root directory of your solution

# Make a directory for build scripts
mkdir Build
cd Build

# Install Fake Globally
dotnet tool install fake-cli -g

# Install the Fake Templates
dotnet new -i "fake-template::*"

# Create a new build script
# dotnet new fake -sn "build.fsx"
touch add-migration.fsx

cd ../ # assumes this takes you to the root directory of your solution

# Add the projects to the solution
dotnet sln [SolutionName].sln add [ApiName]/[ApiName].csproj Migrations/Migrations.csproj

# Trust the self-signed HTTPS Development Cert
dotnet dev-certs https --trust

## IMPORTANT
## If you want to use user-secrets (i.e. dotnet user-secrets set "Foo" "Bar"
## You have to edit the csproj file manually
## Add the following to `PropertyGroup`
## <UserSecretsId>[UUID HERE]</UserSecretsId>
```

Fake Templates:
```
Templates                                         Short Name         Language          Tags
----------------------------------------------------------------------------------------------------------------------------
Console Application                               console            [C#], F#, VB      Common/Console
Class library                                     classlib           [C#], F#, VB      Common/Library
Unit Test Project                                 mstest             [C#], F#, VB      Test/MSTest
xUnit Test Project                                xunit              [C#], F#, VB      Test/xUnit
Razor Page                                        page               [C#]              Web/ASP.NET
MVC ViewImports                                   viewimports        [C#]              Web/ASP.NET
MVC ViewStart                                     viewstart          [C#]              Web/ASP.NET
ASP.NET Core Empty                                web                [C#], F#          Web/Empty
ASP.NET Core Web App (Model-View-Controller)      mvc                [C#], F#          Web/MVC
ASP.NET Core Web App                              razor              [C#]              Web/MVC/Razor Pages
ASP.NET Core with Angular                         angular            [C#]              Web/MVC/SPA
ASP.NET Core with React.js                        react              [C#]              Web/MVC/SPA
ASP.NET Core with React.js and Redux              reactredux         [C#]              Web/MVC/SPA
Razor Class Library                               razorclasslib      [C#]              Web/Razor/Library/Razor Class Library
ASP.NET Core Web API                              webapi             [C#], F#          Web/WebAPI
global.json file                                  globaljson                           Config
NuGet Config                                      nugetconfig                          Config
Web Config                                        webconfig                            Config
Solution File                                     sln                                  Solution
FAKE - Template                                   fake                                 build/FAKE
```

### Allowing connections on the local network

1. In Visual Studio, double-click the project in the left-navigation to open the project options.
2. Click "Run > Configurations > Default"
3. Click the "ASP.NET Core" tab
4. Change the App URL to "https://0.0.0.0:5001"

