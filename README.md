# Qmuni Client Library #

The **Qmuni Client Library** was developed by Qmuni, LLC as a companion project to the Qmuni API. It was created for developers to help them simplify their integration with Qmuni API into their projects. It consists of a core client library and specific platform wrappers.

** *Please review our [disclaimer](#disclaimer) before using this software.* **

## Table of Contents ##
---
1. [Changes](#changes)
1. [Integration](#integration)
1. [Dependencies](#dependencies)
1. [Compile](#compile)
1. [Contact](#contact)
1. [Disclaimer](#disclaimer)

<a name="changes"></a>
## Changes ##
---

Please be patient with us as we address bugs and add new features. If you'd like to report an error, omission, or suggest a feature, please email us at [support@qmuni.com][support].

### Version 1.0 Feature Tracking ###

| Description   | Status |
| :------------ | :----: |
| Logins        |  [ ]   |
| Conversations |  [ ]   |
| Messages      |  [ ]   |
| Attachments   |  [ ]   |

<a name="integration"></a>
## Integration ##
---

The **Qmuni Client Library** seeks to support many different platforms and languages. The project seeks to be compatible and easy to use no matter what you develop on.

### OS Support ###

* Mac OS X (installation instructions below)

### Language Support ###

* C++ using our Makefile
* HTTP REST using the Qmuni REST API
* 4D v14.3 using our Qmuni 4D wrapper plugin

### Planned OS Support ###

* Linux
* Windows 8
* Windows Phone 8
* iOS
* Android

### Planned Language Support ###

* Objective-C
* Java
* JavaScript
* PHP
* Python
* Ruby

<a name="dependencies"></a>
## Dependencies ##
---

The following libraries must be available in order to link programs that use the **Qmuni Client Library**.

* [POCO][] for network connectivity
* [RapidJSON][] for JSON processing

	***Note:** RapidJSON is included as a Git sub-module.*

### Installing Dependencies ###

#### RapidJSON Installation ####

Since [RapidJSON][] is included as a sub-module, you can just execute the following command inside the **qmuni_lib** repository root to check-out the [RapidJSON][] library:

	submodule update --init --recursive

#### POCO Installation ####

##### (for Mac OS X) #####

An easy way to install [POCO][] on Mac OS X is to use [Homebrew][].

First, you must install [Homebrew][]. Then, execute:

	brew install poco

Now that POCO is installed, you will now be able to compile the library.

<a name="compile"></a>
## Compile ##
---

### Execute Test Application ###

	cd src
	make

<a name="contact"></a>
## Contact ##
---

If you need help or support with using our library, please contact us at [support@qmuni.com][support]. We'd love to hear from you.

<a name="disclaimer"></a>
## Disclaimer ##
---

**This project is currently being developed and therefore may have critical bugs or security issues that we have not addressed. We do not advise using this library in any professional business or security sensitive environments at this time. No warranty, expressed or implied, is made regarding accuracy, adequacy, completeness, legality, reliability or usefulness of any information or code provided. This disclaimer applies to both isolated and aggregate uses of the information or code. The information and code is provided on an "as is" basis. All warranties of any kind, express or implied, including but not limited to the implied warranties of merchantability, fitness for a particular purpose, freedom from contamination by computer viruses and non-infringement of proprietary rights are disclaimed. Changes may be periodically made to the information and code herein; these changes may or may not be incorporated in any new version of the information or code. If you have obtained information or code from Qmuni, LLC from a source other than Qmuni, LLC directly, be aware that electronic data can be altered subsequent to original distribution. Data can also quickly become out-of-date. It is recommended that careful attention be paid to the contents of any data associated with a file, and that the originator of the data or information be contacted with any questions regarding appropriate use.**

[poco]:http://pocoproject.org/
[rapidjson]:https://github.com/miloyip/rapidjson
[homebrew]:http://brew.sh/
[support]:mailto:support@qmuni.com