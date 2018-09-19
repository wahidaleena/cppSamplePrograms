from distutils.dir_util import copy_tree
import pkgutil
import importlib
import dm_repo_downloader.plugins
import logging
# import logstash
import os


def iter_namespace(ns_pkg):
    # Specifying the second argument (prefix) to iter_modules makes the
    # returned name an absolute name instead of a relative one. This allows
    # import_module to work without having to do additional modification to
    # the name.
    return pkgutil.iter_modules(ns_pkg.__path__, ns_pkg.__name__ + ".")


repo_downloader_clients = {
    importlib.import_module(name).RepoClientInterface
    for finder, name, ispkg
    in iter_namespace(dm_repo_downloader.plugins)
}


class FSCopier(object):
    def __init__(self):
        self.logger = logging.getLogger(str(self.__class__.__name__))
        # logging.basicConfig(filename="C:\\Users\\u60903\\Downloads\\dm_repo_downloader\\dm_repo_downloader\\plugins\\logFile.txt", filemode='w', level=logging.DEBUG, format='%(asctime)s %(message)s')
        # self.logger.setLevel(logging.DEBUG)
        # self.logger.addHandler(logstash.TCPLogstashHandler(os.environ.get('ALLOWEDHOST', '127.0.0.1'), 5959, version=1))

    def clone_repo(self, src_dir, dst_dir):
        try:
            self.logger.debug("Entering clone repo of FSCopier")
            if os.path.isdir(src_dir) and not os.path.exists(dst_dir):
                copy_tree(src_dir, dst_dir)
        except Exception as e:
            print(e)
            self.logger.error("An exception occurred in clone repo of FSCopier")
        self.logger.debug("Exiting clone repo of FSCopier")


class RepoDownloaderInterface(object):
    def __init__(self):
        self.clients = list(repo_downloader_clients)
        self.logger = logging.getLogger(str(self.__class__.__name__))
        '''logging.basicConfig(
            filename="C:\\Users\\u60903\\Downloads\\dm_repo_downloader\\dm_repo_downloader\\plugins\\logFile.txt",
            filemode='w', level=logging.DEBUG, format='%(asctime)s %(message)s')'''
        # self.logger.setLevel(logging.DEBUG)
        # self.logger.addHandler(logstash.TCPLogstashHandler(os.environ.get('ALLOWEDHOST', '127.0.0.1'), 5959, version=1))

    def clone_repo(self, module_name, repo_url):
        try:
            self.logger.debug("Entering clone repo of RepoDownloaderInterface")
            client_list = [x().get_client_type_from_url(repo_url) for x in self.clients]
            client_ids = [i for i in range(len(client_list)) if client_list[i] != ""]
            if len(client_ids) > 0:
                for client_id in client_ids:
                    clone_complete = self.clients[client_id]().clone_repo(repo_url, module_name)
                    if clone_complete:
                        self.logger.debug("Entering 'if' clone complete for client id in client ids")
                        return clone_complete
        except Exception as e:
            print(e)
            self.logger.error("An exception occurred in clone repo of RepoDownloaderInterface")

        for client in self.clients:
            clone_complete = client().clone_repo(repo_url, module_name)
            try:
                if clone_complete:
                    self.logger.debug("Entering clone complete 'if' for client in clients")
                    return clone_complete
            except Exception as e:
                print(e)
                self.logger.error("Exception in cloning")
        self.logger.debug("Exiting clone repo of RepoDownloaderInterface")
        return False


'''if __name__ == '__main__':
    copyobj=RepoDownloaderInterface()
    copyobj.clone_repo("abc","https://github.com/JDNew/CMakePractice.git")'''
